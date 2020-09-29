<img src="img/logo.png" alt="BPM Game Engine Logo" align="right" width=100 />

# BPM Game Engine

## Features List

### Window System

- Criação de janelas de aplicação baseada em Win32 (Microsoft Windows).
- Diferentes estilos de janelas:
  - GE_WIN_SPLASH (0x01)
  - GE_WIN_DEFAULT (0x02)
  - GE_WIN_DEFAULT_NO_SYS (0x03)
  - GE_WIN_WINDOWED_FULLSCREEN (0x04)
  - GE_WIN_COMPLETE (0x05)    
- Atributos:
  - Título da janela de aplicação
  - Largura e altura configurável
  - Posição na tela (x e y) configurável

### API Wrapper

API Wrapper é responsável por abstrair as funções específicas dos sistemas operacional (Win32).
- Suporte para o gerenciamento de janelas Win32
- Tratamento de eventos e mensagens do Windows (message pump)
- Acesso aos registradores especiais High-Resolution-Timer
- Interface com o hardware gráfico através da GDI
- Troca de buffers (double-buffer)

### Event handler

- frameEvent()
- mouseEvent(int button, int state, int x, int y)
- mouseMotionEvent(int x, int y)
- keyboardEvent(unsigned char key, int state)
- keyboardSpecialEvent(unsigned char key, int state)
- resizeWindowEvent(int width, int height)
- finishAfterEvent()
- finishBeforeEvent()
- resumeEvent()
- pauseEvent()
- beforeMainLoopEvent()

### Motor de renderização

- Tipos de renderização (2D ou 3D)
- Configuração da Viewport e de Window
- Configuração da projeção (Ortográfica ou Perspectiva)
- Configuração do mundo do jogo (definição das paredes e o chão)
- Ativação do v-sync para OpenGL

### Core

- Inicialização dos componentes: sistema de janelas, motor de renderização, etc
- Execução e controle do loop principal
  - frame-rate-governing
  - função pause e resume
- Cálculo de frame time e controle do número de quadros por segundo
- Coleta de log e informações de diagnóstico
- Chamadas de diversos eventos de callback do usuário

### Time Handler

- Utilização de High-Resolution-Timer para o cálculo do frame Time
- Timer interno do momento em que o loop principal é iniciado
- Disponibilização desse do frame time e timer interno para outros componentes: timer, animação, física, etc
- Controle do número de quadros por segundo (estabilidade)

### Timer

- Timer (unidade de tempo em ciclos de CPU por segundo)
- Utilizado para contar tempo em escopo global
- Utilizando dentro de outros componentes como sprites, sistema de física, etc (acesso mais rápido pelo time handler)

### Diagnóstico

- coleta de dados como número de quadros por segundo por um período de tempo
- armazenamento desses dados em um log

### BPMN Parser e a Máquina de Estados
- Interface JNI com scripts Java
- Integração Camunda BPMN API
- Parser de arquivos BPMN e preenchimento da máquina de estados
- Estrutura de dados para as tarefas relacionadas a BPMN

### Sprite e Sprite Manager

- Sprite representa entidades 2D do jogo:
  - Posição no eixo X e Y
  - Velocidade no eixo X e Y
  - Tamanho (largura e altura em pixels)
  - Visibilidade
  - movimentação 2D: x = x + v.t (formula independente do numero de quadros)
  - BOUNDING (LIMITADOR RETANGULAR DE MOVIMENTO DO SPRITE NOS EIXOS X E Y)

  - Retângulo de colisão (X)
  - Raio (círculo) de colisão (X)

- Gerenciamento de sprites através de uma lista ligada

### Level Design
- Criação de níveis atráveis de layers
- Layers construídas a partir de tileset (Atlas)

### Sistema de detecção de colisão

- Tipos de colisão: BA_STOP, BA_WRAP, BA_BOUNCE, BA_DIE

### Biblioteca de matemática e física

- Cálculo de distância entre pontos
- Cálculos trigonométricos (pontos no espaço baseado nos quadrantes)
- Cálculo de correção de aspecto
- Cálculos de velocidade, gravidade e atrito

#### Asset Manager
- Leitor de arquivos BMP, JPEG, OBJ (Wavefront)
- Estrutura para armazenamento de texturas
