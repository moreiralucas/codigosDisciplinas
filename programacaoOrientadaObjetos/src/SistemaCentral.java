import cirurgia.*;
import pessoas.*;
import java.util.ArrayList;
public class SistemaCentral{
    private int idCirurgia = 0;
    private Administrativo responsavel;
    private ArrayList<Paciente> pacientes = new ArrayList<Paciente>();
    private ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();
    private ArrayList<SalaCirurgia> salasDeCirurgia = new ArrayList<SalaCirurgia>();
    
    public static class IdProntuario
    {
        private static int idProntuario = 0;    
        public static int incIdProntuario(){
            IdProntuario.idProntuario++;
            return IdProntuario.idProntuario;
        }
    }
    
    public SistemaCentral(String nome, int rg, int idade, double salario, String login, String senha){
        responsavel = new Administrativo(nome, rg, idade, salario, login, senha);
        System.out.println("Sistema controlado por "+ nome+".");
    }
    
    private int incIdCirurgia(){
        return idCirurgia++;
    }
    
    public void criaPaciente(String nome, int rg, int idade, String motivo){
        pacientes.add(new PacientePrioritario(nome, rg, idade, motivo, IdProntuario.incIdProntuario()));
        System.out.println("Criado o paciente prioritário "+ nome+" de RG "+ rg+".");
    }
    
    public void criaPaciente(String nome, int rg, int idade){
        pacientes.add(new PacienteComum(nome, rg, idade,IdProntuario.incIdProntuario()));
        System.out.println("Criado o paciente "+ nome+" de RG "+ rg+".");
    }
    
    public void criaProfissionalSaude(String nome, int rg, int idade, double salario, String especializacao){
        funcionarios.add(new ProfissionalSaude(nome, rg, idade, salario, especializacao));
        System.out.println("Profissional de saúde "+ nome+" de RG "+ rg +" foi criado.");
    }

    public void criaProfissionalSaude(String nome, int rg, int idade, double salario){
        funcionarios.add(new ProfissionalSaude(nome, rg, idade, salario));
        System.out.println("Profissional de saúde "+ nome+" de RG "+ rg +" foi criado.");
    }
    
    
    public void criaProfissionalGeral(String nome, int rg, int idade, double salario, String funcao){
        funcionarios.add(new ProfissionalGeral(nome, rg, idade, salario, funcao));
        System.out.println("Profissional geral "+ nome+" de RG "+ rg+" foi criado.");
    }
    
    public void criaProfissionalAdministrativo(String nome, int rg, int idade, double salario, String login, String senha){
        funcionarios.add(new Administrativo(nome, rg, idade, salario, login, senha));
        System.out.println("Profissional administrativo "+ nome+" de RG "+ rg+" foi criado.");
    }
    
    public void criaSalaDeCirurgi(int idSala){
        salasDeCirurgia.add(new SalaCirurgia(idSala));
        System.out.println("Sala de cirurgia "+idSala+" foi criada no sistema!");
    }
    
    public void planejarCirurgia(int idSala,String tipoCirurgia, int rgPaciente, double valorTotal){
        Paciente cliente=null;
        cliente = findRgPaciente(rgPaciente);
        if(cliente != null){
            findIdSala(idSala).planejarCirurgia(this.incIdCirurgia(),tipoCirurgia,cliente,valorTotal);
            System.out.println("Cirurgia planejada:\n"+cliente.toString());
        }else
            System.out.println("Nao foi localizado nenhum paciente com o rg: " + rgPaciente+".");
    }
    
    public void finalizarCirurgia(int idSala){
        if (findIdSala(idSala)==null)
            System.out.println("Sala não encontrada!");
        else{
            findIdSala(idSala).finalizarCirurgia();
        }
    }
    
    public void cancelarCirurgia(int idSala){
        if (findIdSala(idSala)==null)
            System.out.println("Sala não encontrada!");
        else{
            findIdSala(idSala).cancelarCirurgia();
        }
    }
    
    public void inserirProfissionalDeSaudeEmCirurgia(int rgDoProfissional,int idSala){
        Funcionario profissional=null;
        try{
            for (int i=0;i<funcionarios.size();i++)
                if (funcionarios.get(i).getRg()==rgDoProfissional)
                    profissional=funcionarios.get(i);
            findIdSala(idSala).inserirProfissionalDeSaudeEmCirurgia(profissional);
            System.out.println("O profissional de saúde "+ profissional.getNome()+" foi colocado na cirurgia "+ idCirurgia+" na sala "+idSala+".");
        }catch(NullPointerException e){
            System.out.println("Ocorreu um erro interno. tente novamente!\nErro:" + e);
        }
    }
    
    private Paciente findRgPaciente(int rgPaciente){
        Paciente cliente=null;
        for (int i=0;i<pacientes.size();i++)
            if (pacientes.get(i).getRg()==rgPaciente)
                cliente=pacientes.get(i);
        return cliente;
    }
    
    private SalaCirurgia findIdSala(int idSala){
        SalaCirurgia sala=null;
        for (int i=0;i<salasDeCirurgia.size();i++)
            if (idSala==salasDeCirurgia.get(i).getIdSala())
                sala=salasDeCirurgia.get(i);
        return sala;
    }
    
}
