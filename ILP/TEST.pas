 procedure Pesquisar;
var
        
Pesq, Aux : string;
     Controle, Achou: Boolean;

                begin
                
                  Controle:=True;
                 Achou:=False;

                  repeat
                             clrscr;
                    write('Pesquisa de Registros');
                   writeln;
                   writeln;
                 write('Especifique o Nome a ser Pesquisado : ');
                       read(Pesq);
                       writeln;
                       write('Procurando por ',Pesq,'.....');
                       writeln;
                       writeln;

                       for i:=1 to n do
 
                               begin
                                                    if (Pesq = Registro[i].nome) then

                                               begin

                                                       writeln;
                                                       Achou:=True;
                                                        write('O termo [',Pesq,'], foi encontrado no Indice [',i,']');
                                                       writeln;
                                                       break;

                                               end

                                        else

                                               writeln('--- Indice [',i,'] nao confere! ---');

                                            end;

                                writeln;

                               if (Achou = True) then

                                       begin
                                
                                               writeln;
                                               write('Resultado da Pesquisa :');
                                               writeln;
                                               writeln;
                                               write('Nome : ',Registro[i].nome);
                                                writeln;
                                               write('Endereco : ',Registro[i].ender);
                                               writeln;
                                               write('Telefone : ',Registro[i].tel);
                                               writeln;
                                               Achou:=False;
                                        
                                       end

                               else

                                       writeln('Sua pesquisa nao obteve resultados,..');
                                        
                                       writeln;
                                       write('Deseja efetuar nova pesquisa ? (S/N) ');
                                       read(Aux);

                               if ((Aux = 'S') or (Aux = 's')) then

                                       Controle:=True

                                else

                                       Controle:=False;

                       until Controle = False;
                        
                       readkey;
                            end;

