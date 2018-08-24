import java.io.*;

public class GerenciadorTemperatura
{
    // instance variables - replace the example below with your own
    private float[] temperaturas;
    private int qtdElementos;//quantidade de elementos preenchidos

    /**
     * Constructor for objects of class GerenciadorTemperatura
     */
    public GerenciadorTemperatura(float[] temp)
    {
        // initialise instance variables
        temperaturas = temp;
        qtdElementos = temperaturas.length;
    }
    
    public GerenciadorTemperatura(int tamanho)
    {
        // initialise instance variables
        temperaturas = new float[tamanho];
        qtdElementos = 0;
    }
    
    public boolean insereTemperatura(float temp)
    {
        if(qtdElementos < temperaturas.length)
        {
            temperaturas[qtdElementos] = temp;
            qtdElementos++;
            return true;
        }
        else
            return false;
    }
    
    public boolean removeTeperatura(float temp)
    {
        for(int i = 0; i < qtdElementos ; i++)
        {
            if(temperaturas[i]==temp)
            {
                for(int j=i+1;j<qtdElementos;j++)
                {
                    temperaturas[i] = temperaturas[j];
                    i++;
                }
                qtdElementos--;
                return true;
            }
        }
        return false;
    }
    
    public float getMaxima()
    {
        float max = temperaturas[0];
        for(int i = 0; i < qtdElementos; i++)
        {
            if(temperaturas[i]>max)
                max = temperaturas[i];
        }
        return max;
    }
    
    public float getMinima()
    {
        float min = temperaturas[0];
        for(int i = 0; i < qtdElementos; i++)
        {
            if(temperaturas[i]<min)
                min = temperaturas[i];
        }
        return min;
    }
    
    public float getAmplitude()
    {
        return (this.getMaxima() - this.getMinima());
    }
    
    public float getMedia()
    {
        float media=0;
        float soma=0;
        for(int i = 0; i < qtdElementos; i++)
        {
            soma = soma + temperaturas[i];
        }
        media = soma/qtdElementos;
        return media;
    }
    
    public void ordenarTemperaturas()
    {
        for(int i = 0; i < qtdElementos; i++)
        {
            for(int k = i+1; k < qtdElementos; k++)
            {
                if(temperaturas[i] > temperaturas[k])
                {
                    float aux = temperaturas[i];
                    temperaturas[i] = temperaturas[k];
                    temperaturas[k] = aux;
                }
            }
        }
    }
    
    public static void main(String args[])
    {
        System.out.println("Gerenciador de Temperaturas:");
    }

}