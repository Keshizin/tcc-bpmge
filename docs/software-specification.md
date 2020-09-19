<img src="img/logo.png" alt="BPM Game Engine Logo" align="right" width=100 />

# Software Specification - BPM Game Engine

## Table of content

- [1. Introdução](#introduction)
- [2. Descrição Geral](#general-description)
- [Processos de Software](#software-process)
- [Engenharia de Requisitos](#requirements-engineering)
- [Modelagem Conceitual](#conceptual-model)
- [Projeto de Software](#software-project)
- [Teste de Software](#software-testing)
- [Gerência de Configuração](#configuration-management)
- [Cronograma do Projeto](#project-schedule)
- [Garantia de Qualidade](#quality-assurance)

## 1. Introdução
Este documento tem como objetivo descrever em detalhes a especificação de projeto de BPM Game Engine, um motor de jogo para desenvolvimento de jogos baseados em processos de negócio.

Esta especificação está dividida em dez capítulos, incluindo a descrição geral de BPM Game Engine e as suas principais funcionalidades, os processos de software aplicados neste projeto, a engenharia de requisitos, arquitetura de software e a sua modelagem conceitual, visão geral das ferramentas utilizadas no desenvolvimento, gerência de configuração e, por fim, a descrição do plano de testes e a garantia de qualidade.

Esta especificação é apenas um de vários de documentos relacionados ao projeto. Existem outros documentos que abrangem outros aspectos do projeto como: o guia de desenvolvimento, listagem de requisitos, planos de testes, guia de usuário e avaliação de desempenho.

Este documento está destinado a todas as pessoas envolvidas no projeto BPM Game Engine.

## 2. Descrição Geral

BPM Game Engine é um motor de jogo que surgiu para apoiar a criação e desenvolvimento de jogos digitais baseados em processos de negócio. Jogos digitais baseados em processos de negócio são caracterizados por jogos que apresentam um processo de negócio de forma ludificada permitindo assim, a compreensão e a aprendizagem do seu funcionamento de forma divertida e engajante.

Além do suporte completo para o desenvolvimento de jogos baseados em processos de negócio, este motor de jogo também pode ser utilizado para criar jogos de diferentes gêneros e propósitos.

Segue a lista das principais funcionalidades de BPM Game Engine:

- Multiplataforma (Windows, Linux e Android)
- Criação e gerenciamento de diferentes estilos de janelas de aplicação
- Tratamento de entrada do jogador com teclado, mouse e controle
- Renderização de objetos 2D (sprites) e objetos 3D (wireframes)
- Simulação de física e sistema de detecção de colisão
- Gerenciamento de recursos externos (BMP, PNG e OBJ)
- Mapeamento de elementos de processos de negócio em elementos de jogos

### Limitações

- Jogos online

## 3. Processos de Software

### Sprint List

#### Sprint #0 - 02/01 to 12/02
Planejamento e organização inicial do repositório.

- Definição do Projeto
- Especificação do sprint #1
- Criação dos documentos iniciais
- Criação da estrutura do projeto

#### Sprint #1 - 13/02 to 27/02
Criação de janelas win32 com diferentes estilos e capturas de eventos do Windows

- Inclusão da classe GEWindowSystem
- Inclusão da classe GEApiWrapper
- Inclusão da classe GEWinApiWrapper
- Tratamento de eventos do Windows (mouse e teclado)
- Criação e exibição de janelas Win32 com diferentes estilos
- Inclusão da classe GEEventHandler
- Inclusão da classe GERenderingSystem (inicialização OpenGL)
- Inclusão do teste de unidade
- Inclusão da avaliação de desempenho
- Inclusão de documentos

#### Sprint #2 - 28/02 to 12/03
Implementação do loop principal, cálculo da duração de cada quadro e o controle do número de quadros por segundo. Coleta de informações de diagnóstico de bpm game engine.

- Inclusão da classe GameEngine
- Implementação do loop principal
- Inclusão da classe GETimeHandler
- Cálculo de duração do tempo do quadro
- Inclusão de acesso aos registrados high-resolution-timer
- Inclusão da classe GETimer
- Inclusão da classe GEDiag
- Cálculo de FPS
- Inclusão da classe GEMouse

#### Sprint #3 - 13/03 to 06/04
Configuração do sistema de renderização: contextos 2D ou 3D, tipos de projeção, definição de window e viewport e controle avançado do loop game com frame-rate-governing e funções de pause e resume

- Inclusão da classe Object
- Inclusão do modo DEBUG através do makefile.
- Inclusão da função pause e resume
- Contexto de jogo 2D ou 3D (perspectiva)
- Atualização no cálculo de FPS
- Implementação de Frame-Rate-Governing
- Inclusão da classe Keyboard
- Atualização dos documentos

#### Sprint #4 - 07/04 to 20/04
Animação básica, integração com BPMN Parser (java).


## Engenharia de Requisitos

## Modelagem Conceitual

## Projeto de Software

## Teste de Software

## Gerência de Configuração

## Cronograma do Projeto

## Garantia de Qualidade
