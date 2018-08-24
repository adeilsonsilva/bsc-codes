public class main
{
public static void main()
    {
       String nome, endereco, titulo, ator;
       long telefone;
       int qtdFilmes, qtdClientes, qtdCopias, lancamento, opc;      
       char opcao, LocCtrl = 'n';
       Locadora Loc=null;
       
       
       do{
         System.out.println("MENU");
         System.out.println("1. Abrir locadora");
         System.out.println("2. Comprar filme");
         System.out.println("3. Associar cliente");
         System.out.println("4. Locar filme");
         System.out.println("5. Valor arrecadado");
         System.out.println("6. Filme mais locado");
         System.out.println("7. Ultimo filme locado");
         System.out.println("0. para sair");
         System.out.print("Digite a opçao desejada: ");
         opc = Keyboard.readInt();
         
         switch(opc){
             case 1:
                System.out.println("\nABRIR LOCADORA");
                System.out.println("Digite o nome da locadora: ");
                nome = Keyboard.readString();
                System.out.println("Digite o endereço da locadora: ");
                endereco = Keyboard.readString();
                System.out.println("Digite o telefone da locadora: ");
                telefone = Keyboard.readLong();
                System.out.println("Deseja informar a quantidade de Filmes e Clientes? [S|N] ");
                opcao = Keyboard.readChar();
                
                 if((opcao == 'S') || (opcao == 's')){
                    System.out.println("Digite a quantidade de filmes: ");
                    qtdFilmes = Keyboard.readInt();
                    System.out.println("Digite a quantidade de clientes: ");
                    qtdClientes = Keyboard.readInt();
                    Loc = new Locadora(nome, endereco, telefone, qtdFilmes, qtdClientes);
                 }
                 else{
                   Loc = new Locadora(nome, endereco, telefone);
                 }
                LocCtrl = 's';
                break;        
             case 2:
                if(LocCtrl == 's'){
                    System.out.println("\nCOMPRAR FILME");
                    System.out.println("Digite o titulo do filme: ");
                    titulo = Keyboard.readString();
                    System.out.println("Digite o nome do ator principal: ");
                    ator = Keyboard.readString();
                    System.out.println("Digite a quantidade de copias: ");
                    qtdCopias = Keyboard.readInt();
                    System.out.println("Gostaria de informar o ano de lançamento? [S|N]");
                    opc = Keyboard.readChar();
                    
                     if((opc == 'S') || (opc == 's')){
                         System.out.println("Digite o ano de lançamento: ");
                         lancamento = Keyboard.readInt();
                         Loc.comprarFilme(titulo, ator, qtdCopias, lancamento);
                     }
                     else{
                         Loc.comprarFilme(titulo, ator, qtdCopias); 
                     }
                }   
                else{
                    System.out.println("Necessario abrir a locadora antes de realizar esta operaçao.");
                }
                break;
             case 3:
                if(LocCtrl == 's'){
                    System.out.println("\nASSOCIAR CLIENTE");
                    System.out.println("Digite o nome do cliente: ");
                    nome = Keyboard.readString();
                    System.out.println("Digite o endereço do cliente: ");
                    endereco = Keyboard.readString();
                    System.out.println("Digite o telefone do cliente: ");
                    telefone = Keyboard.readLong();
                    
                    Loc.associarCliente(nome, endereco, telefone);
                }   
                else{
                    System.out.println("Necessario abrir a locadora antes de realizar esta operaçao.");
                }             
                break;
             case 4:
                if(LocCtrl == 's'){
                    System.out.println("\nLOCAR FILME");
                    System.out.println("Digite o titulo do filme: ");
                    titulo = Keyboard.readString();
        
                    Loc.locarFilme(titulo);
                }
                else{
                    System.out.println("Necessario abrir a locadora antes de realizar esta operaçao.");
                } 
                break;
             case 5:
                if(LocCtrl == 's'){
                    Loc.InformaFaturamento();
                }
                else{
                    System.out.println("Necessario abrir a locadora antes de realizar esta operaçao.");
                } 
                break;
             case 6:
                if(LocCtrl == 's'){
                    Loc.maisLocado();
                }
                else{
                    System.out.println("Necessario abrir a locadora antes de realizar esta operaçao.");
                } 
                break;
             case 7:
                if(LocCtrl == 's'){
                    Loc.ultimoFilmeLocado();
                }
                else{
                    System.out.println("Necessario abrir a locadora antes de realizar esta operaçao.");
                }
                break;
             default:
                break;
         }
       }while(opc != 0); 
    }
}
