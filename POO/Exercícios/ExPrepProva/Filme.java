public class Filme
{
    private String titulo;
    private String ator;
    private String lancamento;
    private String indicacao;
    
    public Filme(String titulo, String ator, String lancamento){
        this(titulo, ator, lancamento, "livre");        
    }

    public Filme(String titulo, String ator, String lancamento, String indicacao){
        this.titulo = titulo;
        this.ator = ator;
        this.lancamento = lancamento;
        this.indicacao = indicacao;
    }

    public String getTitulo(){
        return this.titulo;
    }
    
    public String getAtor(){
        return this.ator;
    }
    
    public String getLancamento(){
        return this.lancamento;
    }
    
    public String getFaixa(){
        return this.indicacao;
    }    
}
