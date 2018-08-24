public class Estudante extends Pessoa
{
    private String escola;
    private String serie;

    public Estudante(String nome, String endereco, String escola, String serie)
    {
        super(nome, endereco);
        this.escola = escola;
        this.serie = serie;
    }

    
    public String getNome()
    {
        return super.getNome();
    }
}
