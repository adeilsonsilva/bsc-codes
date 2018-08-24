
public class Filme
{
    private String titulo;
    private String ator;
    private int qtdCopias;
    private int qtdLocacoes;
    private int lancamento;

   
    public Filme(String titulo, String ator, int qtdCopias){
        this(titulo, ator, qtdCopias, 2014);
    }
    
    public Filme(String titulo, String ator, int qtdCopias, int lancamento)
    {
       this.titulo = titulo;
       this.ator = ator;
       this.qtdCopias = qtdCopias;
       this.lancamento = lancamento;
    }
    
    public String getTitulo (){
        return this.titulo;
    }
    
    public int getQtdCopias(){
        return this.qtdCopias;
    }
    
    public void setQtdCopias(){
        this.qtdCopias--;
        this.qtdLocacoes++;
    }   
    
    public int getQtdLocacoes(){
        return this.qtdLocacoes;
    }
    
}
