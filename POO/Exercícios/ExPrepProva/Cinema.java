import java.util.ArrayList;

public class Cinema
{
  private String nome;
  private String endereco;
  private long telefone;
  private String gerente;
  private double caixa;
  private ArrayList <Sala> salas;
  private ArrayList <Filme> filmes;
  private int qtd_assentos;
  
  public Cinema(String nome, String endereco, long telefone, String gerente, double caixa){
      this(nome, endereco, telefone, gerente, caixa, 0, 0);
  }
  
  public Cinema(String nome, String endereco, long telefone, String gerente, double caixa, int qtd_salas, int qtd_assentos){
      this.nome = nome;
      this.endereco = endereco;
      this.telefone = telefone;
      this.gerente = gerente;
      this.caixa = caixa;
      salas = new ArrayList<Sala>();
      filmes = new ArrayList<Filme>();
      for(int j = 1; j <= qtd_salas; j++){
          salas.ensureCapacity(qtd_salas);
          salas.add(new Sala(j, qtd_assentos));
      }
  }
  
  public void insereFilmes(){
      char resp;
      String titulo;
      String ator;
      String lancamento;
      String faixa;
      
      do{
          System.out.println("\nGostaria de adicionar um novo filme ao cinema? [s/n]");
          resp = Keyboard.readChar();
      
          if(resp == 's'){
              System.out.println("Digite o nome do filme: ");
              titulo = Keyboard.readString();
              System.out.println("Digite o nome do ator principal do filme: ");
              ator = Keyboard.readString();
              System.out.println("Digite o ano de lancamento do filme: ");
              lancamento = Keyboard.readString();
              System.out.println("Digite a classificacao etaria do filme: [Enter para \"livre\"]");
              faixa = Keyboard.readString();
              if(faixa.equals("\n")){
                  filmes.add(new Filme(titulo, ator, lancamento, "livre"));
              }
              else{
                  filmes.add(new Filme(titulo, ator, lancamento, faixa)); 
              }
          }
      }while(resp != 'n');
  }
  
  public void alocaFilmenaSala(){
      char resp;
      int num;
      String titulo;
      String ator="n";
      String lancamento="n";
      String faixa="n";
      
      do{
          System.out.println("\nGostaria de alocar outro filme numa sala? [s/n]");
          resp = Keyboard.readChar();
          
          if(resp == 's'){
            System.out.println("Digite o nome do Filme a ser alocado: ");
            titulo = Keyboard.readString();
            System.out.println("Digite a sala onde o filme sera exibido: ");
            num = Keyboard.readInt();
            
            for(Filme myFilm : filmes) {
                if((myFilm.getTitulo() != null) && (myFilm.getTitulo().equals(titulo))){
                    ator = myFilm.getAtor();
                    lancamento = myFilm.getLancamento();
                    faixa = myFilm.getFaixa();
                }
            }
            
            if((salas.get(num) != null)){
               salas.get(num).setFilme(titulo, ator, lancamento, faixa);
            }
          }  
      }while(resp != 'n');
  
  }
  
  public void setProgramacao(){
      insereFilmes();
      alocaFilmenaSala();
  }  
  
  public void pesquisaFilme(){
     String titulo;
     int aux;
     ArrayList <Integer> num;
     System.out.println("\nDigite o nome do filme: ");
     titulo = Keyboard.readString();
     
     aux = salas.size();
     num = new ArrayList<Integer>(aux);
     
     for(Sala mySala : salas){
        if((mySala.getTitulo() != null) && (mySala.getTitulo().equals(titulo))){
            num.add(salas.indexOf(mySala));
        }
     }
  }
  
  public void vendeIngresso(){
      int qtd_ing;
      int num_sala; 
      int desconto=0;    
      int idade;
      int carteira;
      int total;
      char resp;
      
      System.out.println("Digite o numero da sala: ");
      num_sala = Keyboard.readInt();
      System.out.println("Digite a quantidade de ingressos: ");
      qtd_ing = Keyboard.readInt();
      
      total = qtd_ing * 10;
      
      if(salas.get(num_sala).vendeIngresso(qtd_ing) == true){
          for(int i=0; i<qtd_ing; i++){
              System.out.println("Foram solicitados " +qtd_ing+ " ingressos. Digite a idade do comprador do ingresso " +i);
              idade = Keyboard.readInt();
              
              if(idade < 12){
                  desconto=5;
              }else if(idade > 12){
                 System.out.println("O comprador possui carteira de estudante? [s/n]");
                 resp = Keyboard.readChar();
                 
                 if(resp == 's'){
                    System.out.println("Digite o numero da carteira: ");
                    carteira = Keyboard.readInt();
                 }
                 
                 if(idade < 15){
                     desconto = 4;
                 }else if((idade > 16) && (idade < 20)){
                     desconto = 3;
                 }else if(idade > 20){
                     desconto = 2;
                 }
              }
              
              total -= desconto;
              this.caixa +=total;
              System.out.println("Total a pagar: "+total);
          }
          
          //preco = qtd_ing * 10;
          //this.caixa += preco;
      }
  }
  
  public void fecharCinema(){
      int freq_sala =0, freq_total=0, i=0;
      
      System.out.println("O valor total do caixa diario e de: R$"+this.caixa);
      
      for(Sala mySala : salas){
        ++i;
        freq_sala = mySala.getFrequencia();
        System.out.println(freq_sala+ " pessoa(s) frequentaram a Sala " +i);           
        freq_total += freq_sala; 
      }
      
      System.out.println(freq_total+" pessoa(s) visitaram o Cinema hoje.");
  }
}
