Program Gravar_e_Ler_Arquivos_01;  
 Uses Crt;  
 Type  
  TCliente = Record  
   codigo  : String [6];  
   nome   : String [40];  
   endereco : String [60];  
   telefone : String [10];  
  End;  
 Var  
  Cliente : TCliente;  
  Arquivo : File of TCliente; //Arquivo do tipo TCliente  
  i    : Integer;  
  q    : Integer;  
 Begin  
  ClrScr;  
  // Momento 1 - Gravar o Arquivo  
  // Abre Arquivo  
  Assign (Arquivo,'Clientes.ARQ');  
  {$I-}  
  Reset (Arquivo);  
  // Avan‡ar ate o ultimo registro  
  Seek (Arquivo, FileSize(Arquivo));  
  {$I+}  
  if IORESULT()<>0 then ReWrite(Arquivo);  
  //  
  Write ('Quanto clientes para adicionar (0 para nenhum)?'); ReadLn (q);  
  For i:=1 to q do  
  Begin  
   // Entrada dos Dados  
   Write ('Codigo...: '); ReadLn (Cliente.Codigo);  
   Write ('Nome.....: '); ReadLn (Cliente.Nome);  
   Write ('Endereco.: '); ReadLn (Cliente.Endereco);  
   Write ('Telefone.: '); ReadLn (Cliente.Telefone);  
   // Grava‡Æo  
   Write (Arquivo,Cliente);  
  End;  
  // Fecha Arquivo  
  Close (Arquivo);  
  // Momento 2 - Mostrar os Clientes  
  // Abre Arquivo  
  Assign (Arquivo,'Clientes.ARQ');  
  {$I-}  
  Reset (Arquivo);  
  {$I+}  
  if IORESULT()<>0 then ReWrite(Arquivo);  
  // Ir para o inicio do arquivo  
  Seek (Arquivo,0);  
  // Leia o arquivo at' o final  
  While Not(Eof(Arquivo)) Do  
  Begin  
   Read (Arquivo,Cliente);  
   WriteLn ('Codigo...: ', Cliente.Codigo);  
   WriteLn ('Nome.....: ', Cliente.Nome);  
   WriteLn ('Endereco.: ', Cliente.Endereco);  
   WriteLn ('Telefone.: ', Cliente.Telefone);  
  End;  
  // Fecha Arquivo  
  Close (Arquivo);  
  // Pausa no final do programa  
  ReadLn;  
 End.


Read more: http://professorwellingtontelles.blogspot.com/2011/11/leitura-e-gravacao-de-arquivos-em.html#ixzz20ujN5y22

