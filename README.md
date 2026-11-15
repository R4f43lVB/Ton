# Ton

Ton é um editor de texto para terminal escrito em C puro, sem dependências externas. Ele coloca o terminal em *raw mode* e desenha a tela direto com sequências de escape VT100.

Versão atual: `0.0.1`

## Funcionalidades

- Terminal em *raw mode* (lê tecla por tecla, sem eco e sem buffer de linha)
- Tela renderizada com sequências de escape VT100, usando um buffer de escrita para evitar flicker
- Tela de boas-vindas centralizada com a versão do editor
- Detecção automática do tamanho do terminal
- Navegação com o cursor pela tela

## Requisitos

- Sistema compatível com POSIX (Linux, macOS ou WSL no Windows), já que o editor usa `termios.h`, `unistd.h` e `sys/ioctl.h`
- Compilador C com suporte a C99 (`gcc` ou `clang`)
- `make` (opcional, mas recomendado)

## Como compilar

Com `make`:

```sh
make
```

Sem `make`:

```sh
cc ton.c -o ton -Wall -Wextra -pedantic -std=c99
```

Para remover o binário gerado:

```sh
make clean
```

## Como rodar

```sh
./ton
```

### Atalhos

| Tecla | Ação |
| --- | --- |
| Setas (`↑` `↓` `←` `→`) | Movem o cursor |
| `Home` | Vai para o início da linha |
| `End` | Vai para o fim da linha |
| `Page Up` / `Page Down` | Vão para o topo / fim da tela |
| `Ctrl + Q` | Sai do editor |

## Estrutura do projeto

```
.
├── Makefile   # Regras de build (make / make clean)
├── ton.c      # Código-fonte do editor
└── ton        # Binário compilado (Linux x86-64)
```
