public class main
{
    public static void abrirCinema(){
      System.out.println("\t\t\tBEM VINDO AO SISTEMA DE ADM");
      System.out.println("[1] - Menu de Administrador.");
      System.out.println("[2] - Menu de Cliente.");
      System.out.println("[0] - para sair.");         
    }
    
    public static void menuCliente(){
        
        
    }
    
    
    public static void main()
    {
        int resp=0;
        ArrayList <Cinema> cinemas = new ArrayList<Cinema>();
        
        do{        
          System.out.println("\t\t\tBEM VINDO AO SISTEMA DE GERENCIAMENTO DE CINEMAS");
          System.out.println("[1] - ABRIR NOVO CINEMA.");
          System.out.println("[2] - ADMINISTRAR CINEMA EXISTENTE.");
          System.out.println("[0] - para sair.");
        
          resp = Keyboard.readInt();
          
          if(resp == 1){
             abrirCinema();
          }
          else if(resp == 2){
             administraCinema(); 
          }
          else{
           System.out.println("Opcao invalida. Tente novamente.");    
          }
        }while(resp != 0);
    }
}
