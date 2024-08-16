<!DOCTYPE html>

<h1>Jogo da Forca</h1>

<p>Este é um simples jogo da forca implementado em C. O objetivo do jogo é adivinhar uma palavra aleatória, letra por letra, antes que o número máximo de erros seja alcançado. Se o jogador cometer muitos erros, ele "perde" o jogo.</p>

<h2>Funcionalidades</h2>
<ul>
    <li><strong>Leitura de Palavras</strong>: As palavras são lidas de um arquivo de texto (<code>palavras.txt</code>).</li>
    <li><strong>Geração de Palavras Aleatórias</strong>: Uma palavra é escolhida aleatoriamente a partir das palavras carregadas do arquivo.</li>
    <li><strong>Tabuleiro</strong>: Um tabuleiro que exibe as partes do corpo sendo desenhadas a cada erro.</li>
    <li><strong>Jogo Iterativo</strong>: O jogador pode optar por continuar jogando ou sair ao final de cada partida.</li>
</ul>

<h2>Como Jogar</h2>
<ol>
    <li>O jogo escolherá uma palavra aleatória e exibirá o número de letras na palavra, representadas por underscores (<code>_</code>).</li>
    <li>O jogador deve tentar adivinhar a palavra, digitando uma letra por vez.</li>
    <li>Se a letra estiver correta, ela aparecerá na posição correspondente. Se estiver errada, o número de erros aumentará e uma parte do corpo será desenhada no tabuleiro.</li>
    <li>O jogo continua até que o jogador adivinhe todas as letras da palavra ou atinja o número máximo de 7 erros.</li>
    <li>Ao final da partida, o jogador pode escolher se deseja continuar jogando ou sair.</li>
</ol>

<h2>Estrutura do Código</h2>
<ul>
    <li><strong><code>main()</code></strong>: Função principal que gerencia o fluxo do jogo.</li>
    <li><strong><code>gerar_palavra()</code></strong>: Função responsável por carregar as palavras do arquivo e escolher uma palavra aleatória.</li>
    <li><strong><code>limpar_palavra_ficticia()</code></strong>: Inicializa a palavra fictícia com underscores (<code>_</code>).</li>
    <li><strong><code>mostrar_tabuleiro()</code></strong>: Exibe o estado atual do tabuleiro e a palavra fictícia.</li>
    <li><strong><code>digite_letra()</code></strong>: Solicita ao jogador que digite uma letra.</li>
    <li><strong><code>deixar_maiuscula()</code></strong>: Converte a palavra ou a letra para maiúscula.</li>
    <li><strong><code>procurar()</code></strong>: Verifica se a letra digitada está presente na palavra e atualiza o estado do jogo.</li>
</ul>

<h2>Requisitos</h2>
<ul>
    <li>Um compilador C (como <code>gcc</code>).</li>
    <li>Um arquivo <code>palavras.txt</code> no mesmo diretório do código, contendo uma palavra por linha.</li>
</ul>

<h2>Compilação e Execução</h2>
<ol>
    <li>Compile o código com um compilador C, como <code>gcc</code>:</li>
</ol>
<pre><code>gcc -o forca forca.c</code></pre>

<ol start="2">
    <li>Execute o jogo:</li>
</ol>
<pre><code>./forca</code></pre>

<h2>Exemplo de Arquivo <code>palavras.txt</code></h2>
<pre><code>PROGRAMACAO
DESENVOLVEDOR
COMPUTADOR
ALGORITMO
COMPILADOR</code></pre>

<h2>Licença</h2>
<p>Este projeto é de domínio público. Sinta-se à vontade para usar e modificar o código conforme necessário.</p>

</body>
</html>
