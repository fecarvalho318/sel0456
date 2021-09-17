# Disciplina SEL0456

## Aula 1

### Assuntos da aula:

- Discussão sobre licenças de software
- Diferenças entre kernel e sistemas operacionais
- Sistemas operacionais
- Kernel - funções:
    1. gerenciamento de tarefas
    2. comunicação entre processos
    3. gerenciamento de memória

## Aula 2

### Assuntos da aula:

- Instalação Linux: os alunos precisam instalar Linux, pelo menos em uma máquina virtual para poder acompanhar o curso.
- Os alunos precisam abrir uma conta no Github
- Exemplo de arquivo [markdown](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf)
- [Criação da chave ssh para GitHub](./texto/tutorial_chaves_github.md)
- Commit para o github
- Utilizaremos as linguagens: C, C++ e Python
- Emacs

### Utilizando o Emacs como IDE

Para instalar o Emacs no Ubuntu:

```bash
sudo apt install emacs
```

Infelizmente o Emacs não vem comn as opções habilitadas, e habilitá-las requer um esforço e um tempo muito grande. Felizmente, existem alguns utilitários para isso. Um bom exemplo disso é o [Spacemacs](https://www.spacemacs.org/).
Para instalar o Spacemacs, você pode seguir os passos indicados na web page anterior ou:
  
  ```bash
  cd ~
  git clone https://github.com/syl20bnr/spacemacs ~/.emacs.d
  ```
  
  Aí é só executar o emacs normalmente: 
  
  ```bash
  emacs
  ```
  
  Ele vai perguntar se você prefere o estilo `vim` ou `emacs`. Se você não sabe o que isso quer dizer, escolha `emacs`.
  
  > **Algumas dicas úteis:** pelo fato do Emacs ter sido escrito muito antes do DOS existir, quanto mais do Windows, ele utiliza algumas combinações de teclas pouco familiares aos iniciantes, devido aos diversos modelos de teclados existentes.
  
  > > Quando se quer indicar uma tecla pressionada simultaneamente com a tecla `Control`, por exemplo a tecla `Control` pressionada com a tecla `x`, simultaneamente, indica-se por `C-x`. Para a tecla `Alt` pressionada simultaneamente com uma tecla m, por exemplo, utiliza-se a notação: `M-m`. Em sistemas anteriores ao PC, a tecla `Alt` se chamava `Meta`, por isso o `M-`.
  
  > > A combinação `C-g` é utilizado como `CANCEL`, quando se quer, por exemplo, abortar alguma entrada de texto ou comando.
  
  > > O Emacs usa as teclas de **Cut**, **Copy** e **Paste** diferentes. Para o **Cut**, ele usa `C-w`, para o **Copy**, ele usa `M-w` e para o **Paste**, usa-se C-y. **No entanto**, se você preferir usar `C-x`, `C-c` e `C-v`, você pode escolher a opção `CUA Mode` no menu: `F10`->`Options`->`Use CUA keys`. Para ativar o menu, caso ele não esteja aparecendo, pressione `F10` **ou** `M-x menu-bar-mode`, para deixá-lo permanente. Nessa última opção, a combinação `M-x` irá abrir uma linha de comando para chamar funções internas escrita em `emacs-lisp`, que no caso foi `menu-bar-mode`.
  
  > > Em muitos casos é interessante ativar a barra de ferramentas, com: `M-x tool-bar-mode`.
  
  > > Para se visualizar as opções de comandos pelo menu de teclas, pressione `M-m`, tanto no modo `Emacs` quanto no modo `vim`, ou a tecla `Espaço` no modo `vim`.
  
  Existem muitos guias e tutoriais para o `Emacs` disponíveis na rede. O site oficial é: https://www.gnu.org/savannah-checkouts/gnu/emacs/emacs.html.
  
  Em português: no [IME](https://www.ime.usp.br/~rbrito/texts/emacs.html), [EmacsWiki](https://www.emacswiki.org/emacs/NovatoNoEmacs) e [MIT](http://web.mit.edu/Emacs/source/emacs-23.1/etc/tutorials/TUTORIAL.pt_BR).
  
#### Editando programas em C

Um modo que ajuda muito para programação em C, ou mesmo C++, é através do commando: `M-x semantic-mode` e o `M-x auto-complete-mode`.
  
## Aula 3

### Assuntos da aula:

- Estrutura de programas em C
	- Arquivos de código fonte (.c)
	- Arquivos objeto (.o)
	- Arquivos de cabeçalho (.h)
- Compilador GCC e suas flags
- Makefile:
    Para criação e utilização do makefile no VS Code é necessário instalar uma extensão chamada Makefile Tools.
    Para instalar abra o Quick Open (Ctrl + P) e cole o seguinte comando:
    `ext install ms-vscode.makefile-tools`

## Aula 4

### Assuntos da aula:

- Aplicação dos qualificadores `static`, `volatile`, `register`
- Criação de arquivo `.gitignore`
- Realizando "merge" no repositorio do GitHub
- Utilizando threads
	1. `pthread_create()`
	2. `pthread_join()`
	3. `pthread_exit()`

## Aula 5 (02/09)

### Assuntos da aula:

- Processos: criando processos com `fork` e `exec`
- Usando `man <fcn>` para obter documentação sobre função `<fcn>`
- Uso de semaforo (semaphore.h)
	1. `sem_init()`
	2. `sem_wait()`
	3. `sem_post()`

## Aula 6 (09/09)

### Assuntos da aula:

- [cmake](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- argp
- popen
- pipe
- malloc

## Aula 7

### Assuntos da aula 7:

- gdb: rodando direto em linha de comando e rodando com a IDE Emacs
- lib electric-fence (-lefence): melhor detecção falhas de segmentação de memória

```bash
 sudo apt install electric-fence
```

- assert: testar partes do programa na fase de depuração
- esp32: esp-idf

### Instalação do `esp-idf`

Para instalar o IoT Development Framework da Espressif, siga os seguintes passos:

```bash
cd ~
mkdir esp
cd esp
git clone -b v4.3 --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
./install.sh
```

O processo de instalação está finalizado nesse ponto.

Pode-se copiar um exemplo, dos vários disponíveis e rodar:

```bash
cd ~
mkdir Code
cd Code
cp -a ~/esp/esp-idf/examples/peripherals/ledc .
cd ledc
. ~/esp/esp-idf/export.sh
```

Para editar o exemplo:
```bash
emacs main/ledc_example_main.c
```

```bash
idf.py menuconfig
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```

## Aula 8

### Assuntos da aula

- [Programação Orientada a Objetos](oop1/README.md)
- Exemplo de orientação a objetos em C com opacidade, encapsulamento e integridade. Métodos mínimos: construtor, destrutor, representação em stream e inicializador [range.c](oop1/range.c), [range.h](oop1/range.h) e [oop1/main.c](oop1/main.c)
