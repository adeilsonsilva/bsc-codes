
public class Locadora
{
    private String nome;
    private String endereco;
    private long telefone;
    private int qtdFilmes;
    private int qtdClientes;
    private Filme[] filmes;
    private Cliente[] clientes;
    private int filmesComprados;
    private int clientesAssociados;
    private int caixa;
    private String ultimoLocado;

    public Locadora(String nome, String endereco, long telefone){
        this(nome, endereco, telefone, 100, 100);
    }
    
    public Locadora(String nome, String endereco, long telefone, int qtdFilmes, int qtdClientes){
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.filmes = new Filme[qtdFilmes];
        this.clientes = new Cliente[qtdClientes];
        this.filmesComprados = 0;
        this.clientesAssociados = 0;
        this.caixa = 0;
        this.ultimoLocado = "$no";
    }
    
    public void comprarFilme(String titulo, String ator, int qtdCopias){
        this.filmes[filmesComprados] = new Filme(titulo, ator, qtdCopias, 2014);
        this.filmesComprados++;
    }
    
    
    public void comprarFilme(String titulo, String ator, int qtdCopias, int lancamento){
         this.filmes[filmesComprados] = new Filme(titulo, ator, qtdCopias, lancamento);
         this.filmesComprados++;
    }
    
    public void associarCliente(String nome, String endereco, long telefone){
         this.clientes[clientesAssociados] = new Cliente(nome, endereco, telefone);
         this.clientesAssociados++;
    }
    
    public void locarFilme(String titulo){
       int i; 
       
       for(i=0; i<filmesComprados; i++){
           if((this.filmes[i].getTitulo() == titulo)){
               if(this.filmes[i].getQtdCopias() == 0){
                   System.out.println("Filme esgotado");
                   break;
                }
                
               this.filmes[i].setQtdCopias();
               this.ultimoLocado = this.filmes[i].getTitulo();
               this.caixa += 10;
            }
        }
    }
    
    public void InformaFaturamento(){
        System.out.println(this.caixa);
    }
    
    public void maisLocado(){
        int i;
        int copias = 0, maior = 0;
        String titulo = "$no";
        
        for(i=0; i<filmesComprados; i++){
            if(this.filmes[i].getQtdLocacoes() > maior){
                maior=this.filmes[i].getQtdLocacoes();
            }
        }
        
        
        for(i=0; i<filmesComprados; i++){
            if(this.filmes[i].getQtdLocacoes() == maior){
                maior=this.filmes[i].getQtdLocacoes();
                copias=this.filmes[i].getQtdCopias();
                titulo=this.filmes[i].getTitulo();
            }
        }
        
        System.out.println("\nTitulo: "+titulo+"\nQuantidade de Copias: "+copias);
    }
    
    public void ultimoFilmeLocado(){
        System.out.println(this.ultimoLocado);
    }
}
