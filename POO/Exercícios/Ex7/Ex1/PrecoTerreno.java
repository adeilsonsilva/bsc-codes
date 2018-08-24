
public class PrecoTerreno
{
    public static void CalculaPrecoTerreno()
    {
        double area;
        int  loc;
        
        System.out.println("Digite a area do terreno em metros quadrados: ");
        area = Keyboard.readDouble();
        System.out.println("Digite a localizacao: ");
        loc = Keyboard.readInt();
        
        if(loc == 1){
          System.out.println(area*22);
        } 
        
        else if(loc == 2){
          System.out.println(area*27); 
        } 
        
        else if(loc == 3){
          System.out.println(area*29.50);  
        } 
        
        else if(loc == 4){
          System.out.println(area*31.50);  
        } 
        
        else if(loc ==5){
          System.out.println(area*34.30);  
        }
    }
    
}
