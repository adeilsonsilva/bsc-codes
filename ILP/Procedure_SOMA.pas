Program Psoma ;
Procedure SOMA(a,b:real);
 Begin
  writeln('O resultado �:',(a+b));
 End;
 
 var NUM1,NUM2: Real;
 Resp:Char;

Begin
Clrscr;
 Resp:='s';
     while Resp='s' do	
 	begin
 	
 	writeln('Informe dois n�meros:');
 	readln(Num1,Num2);
 	
 	SOMA(Num1,Num2);
 	writeln;
 	writeln;
 	writeln('Deseja efetuar uma nova soma?');
 	readln(Resp);
 	Clrscr;
 	End;
 	
End.
