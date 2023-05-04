package analisadorlexico;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

public class LeitorArquivo {
    private final static int tam_buffer = 20;
    int [] buffer_leitura;
    int ponteiro;   
    public InputStream input_file;
    int buffer_atual;
    int inicio_lexema;
    private String lexema;
    	
    public LeitorArquivo(String arquivo) {// pega o arquivo de entrada e inicia o buffer
        try {
            input_file= new FileInputStream(arquivo);
            inicializarBuffer();
        } catch (FileNotFoundException ex) {
            // TODO Auto-generated catch block
            Logger.getLogger(LeitorArquivo.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private void inicializarBuffer(){// recarrega o buffer 1 e passa o estado do buffer pra 2
        buffer_atual=2;
        buffer_leitura = new int [tam_buffer*2];// array para armazenar os 2 buffer, ou seja 2 buffer de tamanho 20 cada
        ponteiro=0;        
        inicio_lexema=0;
        lexema="";
        reloadBuffer1();
    }
    private void add_ponteiro(){// controla o ponteiro do arquivo
        ponteiro++;
        if(ponteiro==tam_buffer){// final do primeiro buffer
            reloadBuffer2(); 
        }else if(ponteiro==tam_buffer*2){// final do segundo buffer
            reloadBuffer1();
            ponteiro=0;
        }
    }
    private void reloadBuffer1() {// le o arquivo de entrada byte por byte e armazena no array; buffer da esquerda
        if(buffer_atual==2){// evita carregar o mesmo buffer 2 vezes
            buffer_atual=1;            
                try {
                    for(int i=0; i<tam_buffer; i++){// looping para capturar os caracteres
                        buffer_leitura[i]=input_file.read();
                        if(buffer_leitura[i]==-1){//final do arquivo
                            break;
                        }
                    } 
                }catch (IOException ex) {
                    Logger.getLogger(LeitorArquivo.class.getName()).log(Level.SEVERE, null, ex);
            }            
        }

    }
    private void reloadBuffer2() {// le o arquivo de entrada byte por byte e armazena no array; buffer da direita
        if(buffer_atual==1){// evita carregar o mesmo buffer 2 vezes
            buffer_atual=2;            
                try {
                    for(int i=tam_buffer; i<tam_buffer*2; i++){// looping para capturar os caracteres. *2 para armazenar na segunda metade
                        buffer_leitura[i]=input_file.read();
                        if(buffer_leitura[i]==-1){//final do arquivo
                        break;
                        }
                    }
                } catch (IOException ex) {
                    Logger.getLogger(LeitorArquivo.class.getName()).log(Level.SEVERE, null, ex);
                }
            }        
    }
        
    private int read_buffer(){// funcao para ler o que foi armazenado no buffer, responsável pela logica do ´ponteiro e reloads
        int aux = buffer_leitura[ponteiro];       
        add_ponteiro();
        return aux;
    }
	
    public int lerProximoCaractere() { // funcao para trabalhar lendo os caracteres do buffer, ao inves de ler direto do arquivo      
        int c= read_buffer();
        lexema+=(char)c;
        return c;
    }
    public void retroceder(){// funcao para retornar o ponteiro do arquivo; usado bastante para identificar os tokens com 2 digitos(OpRelacional)
        ponteiro--;
        lexema= lexema.substring(0, lexema.length()-1);//remove ultimo caractere
        if(ponteiro<0){
            ponteiro= tam_buffer * 2 - 1;            
        }
    }
    public void zerar(){// sempre que tentar um padrao e nao conseguir, voltar para o inicio do lexema
        ponteiro=inicio_lexema;
        lexema="";
    }
    public void confirmar(){// encontrou o lexema
        inicio_lexema=ponteiro;
        lexema="";
    }
    public String getLexema(){//recuperar o lexema quando for lido
        return lexema;
    }
         
}