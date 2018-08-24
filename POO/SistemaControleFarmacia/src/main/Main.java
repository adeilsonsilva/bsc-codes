package main;

import GUI.*;
import common.classesPessoas.AdminLoginException;
import common.classesPessoas.Administrador;
import common.classesPessoas.FuncLoginException;
import common.classesPessoas.Funcionario;
import common.classesProdutos.*;
import inOut.*;
import java.util.ArrayList;
import java.util.Date;
import java.text.SimpleDateFormat;

public class Main {

    public static void main(String[] args) {
        ArrayList<Administrador> administradores = new ArrayList<>();
        ArrayList<Funcionario> funcionarios = new ArrayList<>();
        ArrayList<Prateleira> prateleiras = new ArrayList<>();
        String login;
        String senha;
        String cpf;
        String[] test = {"sdfsdf", "iwerj"};
        char resp;
        Date data = new Date();
        SimpleDateFormat dataFormatada = new SimpleDateFormat("dd/MM/yyyy");

        
        Inicio.main(test);

        /*        do{
         System.out.println("BEM VINDO!");
         System.out.println("O programa foi inicializado as: ");
         System.out.println(dataFormatada.format(data));
         System.out.println();
         System.out.println("[1] - Cadastrar Administrador");
         System.out.println("[2] - Cadastrar Funcionario");
         System.out.println("[3] - Prosseguir para Login");
         resp = Keyboard.readChar();
        
         switch(resp){
         case '1':
         Administrador.cadastraAdministrador();
         break;
         case '2':
         Administrador.cadastraFuncionario();
         break;
         }
        
         }while(resp != '3'); */
        /*        do {
         System.out.println("Digite a opção desejada: ");
         System.out.println("[1] - Logar como Administrador");
         System.out.println("[2] - Logar como Funcionário");
         System.out.println("[3] - Sair");
         resp = Keyboard.readChar();
         if (resp == '1') {
         System.out.println("E-mail: ");
         login = Keyboard.readString();
         System.out.println("Senha: ");
         senha = Keyboard.readString();
         try {
         for (Administrador admin : administradores) {
         if (admin.Login(login, senha)) {
         admin.adminLogado();
         break;
         }
         }
         } catch (AdminLoginException e) {
         System.out.println(e.getMessage());
         }
         } else if (resp == '2') {
         System.out.println("CPF: ");
         cpf = Keyboard.readString();
         try {
         for (Funcionario func : funcionarios) {
         if (func.Login(cpf)) {
         func.logado();
         break;
         }
         }
         } catch (FuncLoginException e) {
         System.out.println(e.getMessage());
         }
         }
         } while (resp != '3');*/
    }
}
