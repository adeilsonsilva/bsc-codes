{Programa para gerar um arquivo e gravar dados no arquivo gerado}
program GeraArquivo;
type TRegistro = record
 teste : string[15];
 end;
TArquivo = file of TRegistro;

var Arq : TArquivo;

{Procedimento para gravar dados num arquivo}
procedure GravaDados(var f : TArquivo);
var r : TRegistro;
begin
  writeln('Digite teste (999999999 para encerrar)');
  readln(R.teste);
  writeln('LEU NA TELA 1');
 REPEAT
  IF R.teste <> '999999999'  THEN
   begin
        write(f, r);
        writeln('Digite teste (999999999 para encerrar)');
        readln(R.teste);
        writeln('LEU NA TELA loop');
   end;
 UNTIL R.teste = '999999999' ;
 end;

{Programa principal}
begin
  writeln('inicio do programa principal');
  Assign(Arq, 'G:Folha.arq');
  Rewrite(Arq);
  writeln('arquivo criado vazio');
  GravaDados(Arq);
  writeln('DADOS GRAVADOS');
  readln;
end.
