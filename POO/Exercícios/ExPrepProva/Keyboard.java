/* As seguintes linhas permitem o uso das classes de entrada e saÃ­da e de processamento
   de tokens */
import java.io.*;
import java.util.*;

/**
 * A classe <tt>Keyboard</tt> permite a leitura de dados de tipos nativos e de
 * instÃ¢ncias da classe <tt>String</tt> a partir do teclado. Basicamente esta classe 
 * encapsula o funcionamento do Stream <tt>System.in</tt>, que pode ser usado como 
 * entrada padrÃ£o de dados.
 * <p>                         
 * Esta classe Ã© baseada na classe <tt>EasyIn</tt>, de Peter van der Linden. As
 * principais modificaÃ§Ãµes foram:
 * <ul>
 * <li>Os mÃ©todos sÃ£o estÃ¡ticos para facilitar o uso da classe
 * <li>CriaÃ§Ã£o de mÃ©todos sobrecarregados para que valores <i>default</i> possam ser 
 *     usados
 * <li>Melhor tratamento das exceÃ§Ãµes
 * <li>Reconhecimento de vÃ¡rios valores como booleanos e capacidade de leitura de 
 *     <tt>NaNs</tt> e infinitos para valores dos tipos <tt>float</tt> e 
 *     <tt>double</tt>
 * <li>DescriÃ§Ã£o dos detalhes de implementaÃ§Ã£o com comentÃ¡rios
 * </ul>                        
 * A classe permite o uso de arquivos de respostas (<i>"answer files"</i>), que sÃ£o 
 * arquivos contendo os dados que deveriam ser entrados pelo teclado. A entrada destes 
 * dados pode ser simulada atravÃ©s de redirecionamento de arquivos. Se, por exemplo, 
 * tivermos uma aplicaÃ§Ã£o (classe) <tt>DemoDataKeyboard</tt> e quisermos usar um arquivo 
 * de respostas chamado <tt>dados.dat</tt> que jÃ¡ contÃ©m os dados que devem ser 
 * digitados, podemos executar o comando <tt>java DemoDataKeyboard &lt; dados.dat </tt>
 * para ler os dados do arquivo em vez do teclado. O comando serÃ¡ o mesmo para 
 * os sistemas operacionais Windows e Linux.
 * <p>
 * O suporte a arquivos de respostas Ã© limitado, somente funcionarÃ¡ se todos os dados
 * a serem digitados forem entrados no arquivo de respostas, um em cada linha. 
 * ExceÃ§Ãµes ocorrerÃ£o caso estas regras nÃ£o sejam seguidas.
 * <p>
 * A mensagem original de copyright de Peter van de Linden Ã© mostrada ao final desta
 * listagem. Vale a pena notar que a sintaxe proposta e mostrada na mensagem Ã© 
 * diferente da usada pela classe <tt>Keyboard</tt>.
 * <p>                   
 * O livro <b>"An Introduction to Computer Science Using Java"</b>, de Samuel N. Kamin,
 * M. Dennis Mickunas e Edward M. Reingold (editora McGraw-Hill, ISBN 0-07-034224-5)
 * tambÃ©m apresenta uma classe <tt>Keyboard</tt>, cujo funcionamento e cÃ³digo sÃ£o 
 * diferentes desta.
 *   
 * @author Rafael Santos
 * @version 1.2
 */
public class Keyboard
  {
 /**
  * DeclaraÃ§Ã£o dos campos privados desta classe.
  */
  // O campo is Ã© uma instÃ¢ncia da classe InputStreamReader que serÃ¡ construÃ­da a 
  // partir do stream System.in. Note que jÃ¡ que esta classe sÃ³ tem mÃ©todos estÃ¡ticos,
  // nÃ£o terÃ¡ construtor, mas podemos inicializar instÃ¢ncias de classes da forma mostrada 
  // abaixo.
  private static InputStreamReader is = new InputStreamReader( System.in );
  // O campo br Ã© uma instÃ¢ncia da classe BufferedReader que usa 
  // is como argumento para seu construtor.
  private static BufferedReader br = new BufferedReader( is );
  // O campo st Ã© uma instÃ¢ncia da classe StringTokenizer que serÃ¡ 
  // usada em vÃ¡rios mÃ©todos nesta classe.
  private static StringTokenizer st;
  // O campo nt Ã© uma instÃ¢ncia da classe String que serÃ¡ usada em 
  // vÃ¡rios mÃ©todos nesta classe.
  private static String nt;
  // O campo debug estabelece se mensagens de erro de conversÃ£o e leitura 
  // devem ser mostradas ou nÃ£o. O campo nÃ£o pode ser modificado diretamente, 
  // somente atravÃ©s de mÃ©todos especÃ­ficos descritos abaixo.
  private static boolean debug = false;

 /**
  * O mÃ©todo <tt>getToken</tt> lÃª uma string do <tt>BufferedReader</tt> associado com 
  * a entrada padrÃ£o e retorna uma instÃ¢ncia de <tt>StringTokenizer</tt> contendo os 
  * <i>tokens</i> criados a partir da linha lida. O mÃ©todo Ã© declarado como 
  * <tt>private</tt> pois sÃ³ deverÃ¡ ser chamado a partir de outros mÃ©todos da classe.
  * @return uma instÃ¢ncia de <tt>StringTokenizer</tt> contendo os <i>tokens</i> 
  *         obtidos da linha lida
  * @exception IOException se um erro de entrada e saÃ­da ocorrer.
  * @exception NullPointerException se uma string vazia for lida e tentarmos construir
  *                                 uma instÃ¢ncia de <tt>StringTokenizer</tt> com ela
  * @see java.util.StringTokenizer <tt>StringTokenizer</tt>
  */
  private static StringTokenizer getToken() throws IOException, NullPointerException 
    {
    String s = br.readLine();
    return new StringTokenizer(s);
    } // fim do mÃ©todo getToken

 /**
  * O mÃ©todo <tt>readBoolean</tt> lÃª e retorna um valor do tipo <tt>boolean</tt>. 
  * Este mÃ©todo simplesmente chama o mÃ©todo <tt>readBoolean</tt> com argumentos, 
  * descrito abaixo, considerando o valor <i>default</i> como sendo <tt>true</tt>.
  * @return o valor do tipo boolean lido (ou, em caso de erro de leitura, 
  *         <tt>true</tt>)
  */
  public static boolean readBoolean() 
    {
    return readBoolean(true);
    }

 /**
  * O mÃ©todo <tt>readBoolean</tt> lÃª e retorna um valor do tipo <tt>boolean</tt>. Este 
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o e o compara
  *  com algumas strings constantes para verificar a igualdade, retornando <tt>true</tt> 
  * ou <tt>false</tt> dependendo do resultado da comparaÃ§Ã£o.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler e decodificar
  *                     um valor booleano
  * @return o valor do tipo <tt>boolean</tt> lido (ou, em caso de erro de leitura, igual ao 
  *         argumento passado para o mÃ©todo)
  */
  public static boolean readBoolean(boolean defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // Retorna true se a string for igual a...
      if (nt.equalsIgnoreCase("true") ||        // true
          nt.equalsIgnoreCase("t") ||           // t
          nt.equalsIgnoreCase("yes") ||         // yes
          nt.equalsIgnoreCase("y") ||           // y
          nt.equalsIgnoreCase("on") ||          // on
          nt.equalsIgnoreCase("v") ||           // v
          nt.equalsIgnoreCase("s") ||           // s
          nt.equalsIgnoreCase("sim") ||         // sim
          nt.equalsIgnoreCase("verdadeiro"))    // verdadeiro
          return true; 
      // Retorna false se a string for igual a...
      else if (nt.equalsIgnoreCase("false") ||  // false
               nt.equalsIgnoreCase("f") ||      // f
               nt.equalsIgnoreCase("no") ||     // no
               nt.equalsIgnoreCase("n") ||      // n
               nt.equalsIgnoreCase("off") ||    // off
               nt.equalsIgnoreCase("nao") ||    // nao
               nt.equalsIgnoreCase("nÃ£o") ||    // nÃ£o
               nt.equalsIgnoreCase("falso"))    // falso
          return false; 
      // Se nÃ£o for nenhum dos valores reconhecidos, retorna o default
      else return defaultvalue;
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um boolean. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um boolean. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readBoolean

 /**
  * O mÃ©todo <tt>readByte</tt> lÃª e retorna um valor do tipo <tt>byte</tt>. Este 
  * mÃ©todo simplesmente chama o mÃ©todo <tt>readByte</tt> com argumentos, descrito 
  * abaixo, considerando o valor <i>default</i> como sendo <tt>(byte)0</tt>.
  * @return o valor do tipo <tt>byte</tt> lido (ou, em caso de erro de leitura, 
  *         <tt>(byte)0</tt>)
  */
  public static byte readByte() 
    {
    return readByte((byte)0);
    } // fim do mÃ©todo readByte

 /**
  * O mÃ©todo <tt>readByte</tt> lÃª e retorna um valor do tipo <tt>byte</tt>. Este 
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o e o 
  * passa como argumento para o mÃ©todo <tt>parseByte</tt> da classe <tt>Byte</tt>, 
  * que tenta convertÃª-lo. Se a leitura e conversÃ£o puderem ser feitas, um valor
  * do tipo <tt>byte</tt> Ã© retornado, caso contrÃ¡rio o valor <i>default</i> 
  * (passado como argumento) Ã© retornado.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler e 
  *                     decodificar um valor do tipo <tt>byte</tt>
  * @return o valor do tipo <tt>byte</tt> lido (ou, em caso de erro de leitura, 
  *         igual ao argumento passado para o mÃ©todo)
  */
  public static byte readByte(byte defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // retorna o valor processado pela classe Byte
      return Byte.parseByte(nt);
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um byte. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NumberFormatException nfe) // se houver algum erro de conversÃ£o
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de conversÃ£o de "+nt+" para um byte. "+
                           "Retorna "+defaultvalue);
      return defaultvalue;
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um byte. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readByte

 /**
  * O mÃ©todo <tt>readShort</tt> lÃª e retorna um valor do tipo <tt>short</tt>. 
  * Este mÃ©todo simplesmente chama o mÃ©todo <tt>readShort</tt> com argumentos, 
  * descrito abaixo, considerando o valor <i>default</i> como sendo <tt>(short)0</tt>.
  * @return o valor do tipo <tt>short</tt> lido (ou, em caso de erro de leitura, 
  *         <tt>(short)0</tt>)
  */
  public static short readShort() 
    {
    return readShort((short)0);
    } // fim do mÃ©todo readShort

 /**
  * O mÃ©todo <tt>readShort</tt> lÃª e retorna um valor do tipo <tt>short</tt>. Este 
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o e o passa 
  * como argumento para o mÃ©todo <tt>parseShort</tt> da classe <tt>Short</tt>, que 
  * tenta convertÃª-lo. Se a leitura e conversÃ£o puderem ser feitas, um valor do tipo 
  * <tt>short</tt> Ã© retornado, caso contrÃ¡rio o valor <i>default</i> (passado 
  * como argumento) Ã© retornado.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler e 
  *                     decodificar um valor do tipo short
  * @return o valor do tipo <tt>short</tt> lido (ou, em caso de erro de leitura, 
  *         igual ao argumento passado para o mÃ©todo)
  */
  public static short readShort(short defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // retorna o valor processado pela classe Short
      return Short.parseShort(nt);
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um short. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NumberFormatException nfe) // se houver algum erro de conversÃ£o
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de conversÃ£o de "+nt+" para um short. "+
                           "Retorna "+defaultvalue);
      return defaultvalue;
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um short. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readShort

 /**
  * O mÃ©todo <tt>readInt</tt> lÃª e retorna um valor do tipo <tt>int</tt>. Este
  * mÃ©todo simplesmente chama o mÃ©todo <tt>readInt</tt> com argumentos, descrito 
  * abaixo, considerando o valor <i>default</i> como sendo <tt>0</tt>.
  * @return o valor do tipo <tt>int</tt> lido (ou, em caso de erro de leitura,
  *         </tt>0</tt>)
  */
  public static int readInt() 
    {
    return readInt(0);
    } // fim do mÃ©todo readInt

 /**
  * O mÃ©todo <tt>readInt</tt> lÃª e retorna um valor do tipo <tt>int</tt>. Este
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o e o 
  * passa como argumento para o mÃ©todo <tt>parseInt<tt> da classe <tt>Integer</tt>,
  * que tenta convertÃª-lo. Se a leitura e conversÃ£o puderem ser feitas, um valor 
  * do tipo <tt>int</tt> Ã© retornado, caso contrÃ¡rio o valor <i>default</i> 
  * (passado como argumento) Ã© retornado.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler e 
  *                     decodificar um valor do tipo <tt>int</tt>
  * @return o valor do tipo <tt>int</tt> lido (ou, em caso de erro de leitura, 
  *         igual ao argumento passado para o mÃ©todo)
  */
  public static int readInt(int defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // retorna o valor processado pela classe Integer
      return Integer.parseInt(nt);
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um int. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NumberFormatException nfe) // se houver algum erro de conversÃ£o
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de conversÃ£o de "+nt+" para um int. "+
                           "Retorna "+defaultvalue);
      return defaultvalue;
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um int. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readInt

 /**
  * O mÃ©todo <tt>readLong</tt> lÃª e retorna um valor do tipo <tt>long</tt>. Este
  * mÃ©todo simplesmente chama o mÃ©todo <tt>readLong</tt> com argumentos, descrito
  * abaixo, considerando o valor <i>default</i> como sendo <tt>0l</tt>.
  * @return o valor do tipo <tt>long</tt> lido (ou, em caso de erro de leitura, 
  *         <tt>0l</tt>)
  */
  public static long readLong() 
    {
    return readLong(0l);
    } // fim do mÃ©todo readLong

 /**
  * O mÃ©todo <tt>readLong</tt> lÃª e retorna um valor do tipo <tt>long</tt>. Este 
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o e o 
  * passa como argumento para o mÃ©todo <tt>parseLong</tt> da classe <tt>Long</tt>,
  * que tenta convertÃª-lo. Se a leitura e conversÃ£o puderem ser feitas, um valor 
  * do tipo <tt>long</tt> Ã© retornado, caso contrÃ¡rio o valor <i>default</i> 
  * (passado como argumento) Ã© retornado.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler e 
  *                     decodificar um valor do tipo <tt>long</tt>
  * @return o valor do tipo <tt>long</tt> lido (ou, em caso de erro de leitura, 
  *         igual ao argumento passado para o mÃ©todo)
  */
  public static long readLong(long defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // retorna o valor processado pela classe Long
      return Long.parseLong(nt);
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um long. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NumberFormatException nfe) // se houver algum erro de conversÃ£o
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de conversÃ£o de "+nt+" para um long. "+
                           "Retorna "+defaultvalue);
      return defaultvalue;
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um long. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readLong

 /**
  * O mÃ©todo <tt>readFloat</tt> lÃª e retorna um valor do tipo <tt>float</tt>. Este 
  * mÃ©todo simplesmente chama o mÃ©todo <tt>readFloat</tt> com argumentos, descrito 
  * abaixo, considerando o valor <i>default</i> como sendo <tt>0f</tt>.
  * @return o valor do tipo <tt>float</tt> lido (ou, em caso de erro de leitura, 
  *         <tt>0f</tt>)
  */
  public static float readFloat() 
    {
    return readFloat(0f);
    } // fim do mÃ©todo readFloat

 /**
  * O mÃ©todo <tt>readFloat</tt> lÃª e retorna um valor do tipo <tt>float</tt>. Este 
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o e o 
  * analisa, verificando se aparentemente Ã© <tt>NaN</tt> ou infinito. Se nÃ£o for, 
  * passa o valor lido como argumento para o mÃ©todo <tt>parseFloat</tt> da classe 
  * <tt>Float</tt>, que tenta convertÃª-lo. Se a leitura e conversÃ£o puderem ser 
  * feitas, um valor do tipo <tt>float</tt> Ã© retornado, caso contrÃ¡rio o valor
  * <i>default</i> (passado como argumento) Ã© retornado.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler e decodificar
  *                     um valor do tipo <tt>float</tt>
  * @return o valor do tipo <tt>float</tt> lido (ou, em caso de erro de leitura, 
  *         igual ao argumento passado para o mÃ©todo)
  */
  public static float readFloat(float defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // Verifica se o valor Ã© aparentemente NaN ou infinito
      if (nt.toLowerCase().startsWith("nan")) return Float.NaN;
      else if (nt.toLowerCase().startsWith("inf")) return Float.POSITIVE_INFINITY;
      else if (nt.toLowerCase().startsWith("+inf")) return Float.POSITIVE_INFINITY;
      else if (nt.toLowerCase().startsWith("-inf")) return Float.NEGATIVE_INFINITY;
      // Retorna o valor processado pela classe Float
      else return Float.parseFloat(nt);
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um float. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NumberFormatException nfe) // se houver algum erro de conversÃ£o
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de conversÃ£o de "+nt+" para um float. "+
                           "Retorna "+defaultvalue);
      return defaultvalue;
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um float. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readFloat

 /**
  * O mÃ©todo <tt>readDouble</tt> lÃª e retorna um valor do tipo <tt>double</tt>. 
  * Este mÃ©todo simplesmente chama o mÃ©todo <tt>readDouble</tt> com argumentos, 
  * descrito abaixo, considerando o valor <i>default</i> como sendo <tt>0.0</tt>.
  * @return o valor do tipo <tt>double</tt> lido (ou, em caso de erro de leitura, 
  *         <tt>0.0</tt>)
  */
  public static double readDouble() 
    {
    return readDouble(0.0);
    } // fim do mÃ©todo readDouble

 /**
  * O mÃ©todo <tt>readDouble</tt> lÃª e retorna um valor do tipo <tt>double</tt>. Este
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o, 
  * analisando o valor para ver se Ã© <tt>NaN</tt> ou infinito, e se nÃ£o for, usa o 
  * valor como argumento para o mÃ©todo <tt>parseDouble</tt> da classe <tt>Double</tt>,
  * que tenta convertÃª-lo. Se a leitura e conversÃ£o puderem ser feitas, um valor 
  * do tipo <tt>double</tt> Ã© retornado, caso contrÃ¡rio o valor <i>default</i> 
  * (passado como argumento) Ã© retornado.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler e 
  *                     decodificar um valor do tipo <tt>double</tt>
  * @return o valor do tipo <tt>double</tt> lido (ou, em caso de erro de leitura, 
  *         igual ao argumento passado para o mÃ©todo)
  */
  public static double readDouble(double defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // Verifica se o valor Ã© aparentemente NaN ou infinito
      if (nt.toLowerCase().startsWith("nan")) return Double.NaN;
      else if (nt.toLowerCase().startsWith("inf")) return Double.POSITIVE_INFINITY;
      else if (nt.toLowerCase().startsWith("+inf")) return Double.POSITIVE_INFINITY;
      else if (nt.toLowerCase().startsWith("-inf")) return Double.NEGATIVE_INFINITY;
      // Retorna o valor processado pela classe Double
      return Double.parseDouble(nt);
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um double. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NumberFormatException nfe) // se houver algum erro de conversÃ£o
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de conversÃ£o de "+nt+" para um double. "+
                           "Retorna "+defaultvalue);
      return defaultvalue;
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um double. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readDouble

 /**
  * O mÃ©todo <tt>readChar</tt> lÃª e retorna um valor do tipo <tt>char</tt>. Este
  * mÃ©todo simplesmente chama o mÃ©todo <tt>readChar</tt> com argumentos, descrito
  * abaixo, considerando o valor <i>default</i> como sendo <tt>' '</tt> (espaÃ§o).
  * @return o valor do tipo <tt>char</tt> lido (ou, em caso de erro de leitura, 
  *         espaÃ§o)
  */
  public static char readChar() 
    {
    return readChar(' ');
    } // fim do mÃ©todo readChar

 /**
  * O mÃ©todo <tt>readChar</tt> lÃª e retorna um valor do tipo <tt>char</tt>. Este 
  * mÃ©todo tenta pegar o prÃ³ximo <i>token</i> a ser lido da entrada padrÃ£o e retorna
  * o primeiro caractere deste <i>token</i>, ignorando os outros. Se a leitura puder ser 
  * feita, um valor do tipo <tt>char</tt> Ã© retornado, caso contrÃ¡rio o valor
  * <i>default</i> (passado como argumento) Ã© retornado.
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler um valor do tipo
  *                     <tt>char</tt>
  * @return o valor do tipo <tt>char</tt> lido (ou, em caso de erro de leitura, igual ao 
  *         argumento passado para o mÃ©todo)
  */
  public static char readChar(char defaultvalue) 
    {
    try 
      {
      st = getToken(); // pega os tokens a partir da linha lida
      nt = st.nextToken(); // e a primeira string do token.
      // retorna o primeiro caractere da string acima
      return nt.charAt(0);
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo um char. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    catch (NoSuchElementException nsee) // se nÃ£o houver tokens
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Entrada nÃ£o contÃ©m um char. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readChar

 /**
  * O mÃ©todo <tt>readString</tt> lÃª e retorna uma instÃ¢ncia da classe <tt>String</tt>.
  * Este mÃ©todo simplesmente chama o mÃ©todo <tt>readString</tt> com argumentos, descrito
  * abaixo, considerando o valor <i>default</i> como sendo <tt>""</tt> (string vazia).
  * @return o valor da string lida (ou, em caso de erro de leitura, uma string
  *         vazia)
  */
  public static String readString() 
    {
    return readString("");
    } // fim do mÃ©todo readString

 /**
  * O mÃ©todo <tt>readString</tt> lÃª e retorna uma instÃ¢ncia da classe <tt>String</tt>. 
  * Este mÃ©todo retorna uma linha inteira lida da entrada padrÃ£o, sem processÃ¡-la como
  * <i>tokens</i>. Se a leitura puder ser feita, a string lida Ã© retornada, caso 
  * contrÃ¡rio o valor <i>default</i> (passado como argumento) Ã© retornado. O valor
  * <i>default</i> tambÃ©m Ã© retornado no caso de uma string vazia. 
  * @param defaultvalue o valor <i>default</i> caso nÃ£o seja possÃ­vel ler uma instÃ¢ncia
  *                     da classe <tt>String</tt>
  * @return o valor da string lida (ou, em caso de erro de leitura, igual ao 
  *         argumento passado para o mÃ©todo)
  */
  public static String readString(String defaultvalue) 
    {
    try 
      {
      nt = br.readLine(); // uma string lida diretamente 
      if (nt.trim().length() == 0) // nada foi entrado, entÃ£o
        return defaultvalue; // retorna o valor default
      else return nt; // retorna o que foi lido
      }
    catch (IOException ioe) // se houver algum erro de leitura
      {
      if (debug) // se for pedida a impressÃ£o de mensagens de erro
        System.err.println("KEYBOARD:: Erro de entrada e saÃ­da lendo uma string. "+
                           "Retorna "+defaultvalue);
      return defaultvalue; // retorna o valor default
      }
    } // fim do mÃ©todo readString

 /**
  * O mÃ©todo <tt>debugOn</tt> modifica o campo que indica que mensagens de erro 
  * deverÃ£o ser mostradas, fazendo com que sejam mostradas atÃ© que o mÃ©todo 
  * <tt>debugOff</tt> seja chamado.
  */
  public static void debugOn() 
    {
    debug = true;
    System.err.println("KEYBOARD:: Mostrando mensagens de erro e avisos...");
    } // fim do mÃ©todo debugOn

 /**
  * O mÃ©todo <tt>debugOff</tt> modifica o campo que indica que mensagens de erro 
  * deverÃ£o ser mostradas, fazendo com que nÃ£o sejam mostradas atÃ© que o mÃ©todo 
  * <tt>debugOn</tt> seja chamado.
  */
  public static void debugOff() 
    {
    debug = false;
    } // fim do mÃ©todo debugOff

  } // fim da classe Keyboard

// Segue a mensagem original da classe EasyIn de Peter van der Linden

// Simple input from the keyboard for all primitive types. ver 1.0
// Copyright (c) Peter van der Linden,  May 5 1997.
//     corrected error message 11/21/97
//
// The creator of this software hereby gives you permission to:
//  1. copy the work without changing it
//  2. modify the work providing you send me a copy which I can
//     use in any way I want, including incorporating into this work.
//  3. distribute copies of the work to the public by sale, lease, 
//     rental, or lending
//  4. perform the work
//  5. display the work
//  6. fold the work into a funny hat and wear it on your head.
//
// This is not thread safe, not high performance, and doesn't tell EOF.
// It's intended for low-volume easy keyboard input.
// An example of use is:
//     EasyIn easy = new EasyIn();
//     int i = easy.readInt();   // reads an int from System.in
//     float f = easy.readFloat();   // reads a float from System.in