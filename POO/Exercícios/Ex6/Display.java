

public class Display
{
   private int dimensaoHorizontal;
   private int dimensaoVertical;
   private String texto;

    public Display(int dH, int dV, String texto)
    {
        this.dimensaoHorizontal = dH;
        this.dimensaoVertical = dV;
        this.texto = texto;
    }

    public void getDimensaoHorizontal()
    {
        System.out.println(this.dimensaoHorizontal);
    }
    
    public void getDimensaoVertical()
    {
        System.out.println(this.dimensaoVertical);
    }  
    
    public void getTexto()
    {
        System.out.println(this.texto);
    } 
    
    public void setTexto(String texto)
    {
        this.texto = texto;
    }     
}
