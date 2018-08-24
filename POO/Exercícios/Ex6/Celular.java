
public class Celular
{
    private String modelo;
    private int memoria;
    private boolean tocaMP3;
    private long numDiscado;
    private Display disp;

    public Celular(int dH, int dV, String modelo, String texto, int memoria, boolean tocaMP3){
        disp=new Display(dH, dV, texto);
        this.modelo=modelo;
        this.memoria=memoria;
        this.tocaMP3=tocaMP3;
        
    }
    
    public Celular(String modelo, int memoria, boolean tocaMP3){
        this.modelo=modelo;
        this.memoria=memoria;
        this.tocaMP3=tocaMP3;       
    }

    public int getMemoria(){
       return this.memoria;
    }
    
    public void exibeDimensoes(){
        disp.getDimensaoHorizontal();
        disp.getDimensaoVertical();
    }
    
    public void discar(long num){
        this.numDiscado=num;       
    }    
    
    public void exibeTexto(){
        disp.getTexto();  
    }
    
    public void limparDisplay(){
        disp.setTexto("");        
    }
 
}
