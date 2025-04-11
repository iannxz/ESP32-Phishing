
# Captive Portal Personalizado com ESP32 — Phishing Ético

![ESP32 Projeto](https://1.bp.blogspot.com/-GuWilb37otg/XTe1FBKampI/AAAAAAAADe8/nLT2nCWXoD0mqk4-SD7yUHiod4jCyA2JQCLcBGAs/s400/ESP32-Module.png)

## 📌 Descrição

Este projeto demonstra, de forma educativa, como redes WiFi abertas podem ser exploradas com um **ESP32** configurado como um ponto de acesso falso (fake AP). Ao se conectar à rede, o usuário é automaticamente redirecionado para uma **página de login simulada**, semelhante a serviços reais (como Instagram), onde possíveis dados inseridos são armazenados localmente.

> ⚠️ Este projeto tem fins **exclusivamente educacionais e de conscientização em segurança digital**.

---

## 🔧 Recursos

- 🔌 **Compatível com ESP32**  
  Desenvolvido especificamente para placas ESP32, aproveitando suas capacidades de rede avançadas.

- 💻 **Portal Captive Personalizado**  
  Página web imita o layout de redes sociais populares para fins de simulação e testes.

- 📥 **Armazenamento Local de Credenciais**  
  Dados enviados são salvos e podem ser acessados via a rota protegida `/pass`.

- 🛡️ **Proteção com Senha**  
  Acesso à lista de dados capturados só é possível mediante autenticação.

---

## 🧰 O que você vai precisar

- Placa de desenvolvimento **ESP32**
- **Arduino IDE** com suporte à placa ESP32
- Plugin SPIFFS (opcional, se desejar servir arquivos externos)

---

## 🚀 Como usar

1. **Clone o repositório**  
   `git clone https://github.com/iannxz/ESP32-Phishing`

2. **Abra no Arduino IDE**  
   Certifique-se de ter a placa "ESP32 Dev Module" instalada nas preferências.

3. **Configure a rede falsa**  
   No código, defina o nome do WiFi (`SSID_NAME`) e personalize o layout da página se desejar.

4. **Compile e envie para o ESP32**

5. **Conecte-se à rede** gerada e observe o comportamento do captive portal.

---

## ⚠️ Aviso Legal

Este código é disponibilizado **apenas para fins de testes e aprendizado**.  
**Jamais utilize em redes de terceiros ou para obter informações sem permissão.**  
O uso indevido pode ser considerado crime, conforme as leis de sua região.

---

## 🤝 Colabore

Tem ideias para melhorar o projeto? Achou um bug?  
Pull requests e sugestões são bem-vindos!

---

## 📄 Licença

Distribuído sob a licença [MIT](https://opensource.org/licenses/MIT).  
Sinta-se livre para usar, modificar e compartilhar — com os devidos créditos.

---

## 🙏 Créditos

Este projeto foi inspirado por iniciativas anteriores como a de [@HUGOW04](https://github.com/HUGOW04/FakeWifi), com ajustes visuais e funcionais para o ESP32.

---

## 💬 Contato

https://www.linkedin.com/in/iannarthur/

---


