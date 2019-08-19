// comentários escritos por Gabriel Schnorrenberger.

// pinos do teclado:
// 1 pino = 28 2 pino = 27 3 pino = 26 4 pino = 25
// 5 pino = 24 6 pino = 23 7 pino = 28
// pinos de 1 a 4 = linhas do teclado de cima pra baixo.
// pinos de 5 a 7 = colunas do teclado da esquerda pra direita.

// arrays com pinos digitais do arduino na sequencia dos pinos do teclado.
int pinLinhas[] = {28, 27, 26, 25};
int pinColunas[] = {24, 23, 22};

// array de chars representando cada tecla do teclado.
char teclas[4][3] = {{'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'},
                     {'*', '0', '#'}};

void setup() {
  // put your setup code here, to run once:

  // percorre toda lista de pinos das linhas.
  for(int numeroLinhas = 0; numeroLinhas < 4; numeroLinhas++){
    // define o pino como saida.
    pinMode(pinLinhas[numeroLinhas], OUTPUT);
    // envia correte eletrica 5v para as saidas dos pinos.
    digitalWrite(pinLinhas[numeroLinhas], HIGH);
  }

  // percorre toda lista de pinos das colunas.
  for(int numeroColunas = 0; numeroColunas < 3; numeroColunas++){
    // define o pino das colunas como entrada de pullup para verificar se recebeu corrente.
    pinMode(pinColunas[numeroColunas], INPUT_PULLUP); // o pullup significa que se não receber energia interpreta como ligado.
  }

  // inicia comunicação serial.
  Serial.begin(9600);
  // print inicial.
  Serial.print("teclado 4x3!");
  Serial.println();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // percorre novamente o array de linhas.
  for(int numeroLinhas = 0; numeroLinhas < 4; numeroLinhas++){
    // desliga uma das linhas.
    digitalWrite(pinLinhas[numeroLinhas], LOW);


    //percorre o array de colunas.
    for(int numeroColunas = 0; numeroColunas < 3; numeroColunas++){
      
      // verifica se a coluna referente a "numeroColunas" interpreta a entrada pullup como desligado
      // caso isso ocorra significa que o botão [numeroLinhas][numeroColunas] foi pressionado. e será executado o codigo dentro do if.
      if(digitalRead(pinColunas[numeroColunas]) == LOW){
        // exibe a tecla pressionada no monitor serial.
        Serial.print("tecla: ");
        Serial.println(teclas[numeroLinhas][numeroColunas]);
        
        // esta repetição serve para impedir que seja identificado varios click invés de 1.
        while(digitalRead(pinColunas[numeroColunas]) == LOW){
        }
        
      }
    }

    // religa a porta inicialmente desligada para que a proxima passe pelo mesmo processo.
    digitalWrite(pinLinhas[numeroLinhas], HIGH);
  }

  delay(10);
}
