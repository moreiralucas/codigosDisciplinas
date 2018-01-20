package cirurgia;
import pessoas.*;
import java.util.ArrayList;

public class FormularioDeCirurgia{
    private int idCirurgia;
    private String tipoCirurgia;
    private ArrayList<Funcionario> profissionaisEnvolvidos = new ArrayList<Funcionario>();
    private Paciente paciente;
    private double valorTotal;
    private String statusDaCirurgia; // Planejada Iniciada Finalizada Cancelada

    public FormularioDeCirurgia(int idCirurgia, String tipoCirurgia, Paciente paciente, double valorTotal) {
        this.idCirurgia = idCirurgia;
        this.tipoCirurgia = tipoCirurgia;
        this.paciente = paciente;
        this.valorTotal = valorTotal;
        this.statusDaCirurgia = "Planejada";
    }
    
    public void inserirProfissionalDeSaudeEmCirurgia(Funcionario prof){
        profissionaisEnvolvidos.add(prof);
        System.out.println("Profissional inserido com sucesso!");
    }
    
    public int getIdCirurgia(){
        return idCirurgia;
    }
    
    public void adicionarProfissionalNestaCirurgia(ProfissionalSaude envolvido){
        if (envolvido.getAtivo()==true){
            if (statusDaCirurgia!="Finalizada" && statusDaCirurgia!="Cancelada")
                profissionaisEnvolvidos.add(envolvido);
        }else
            System.out.println("Profissional inativo, não selescionável para a cirurgia.");
    }
    
    public void setStatusDaCirurgia(String status){
        if (statusDaCirurgia!="Finalizada" && statusDaCirurgia!="Cancelada")
            statusDaCirurgia=status;
    }
    
    public void finalizarCirurgia(){
        statusDaCirurgia="Finalizada";
    }
    
    public void cancelarCirurgia(){
        statusDaCirurgia="Cancelada";
    }
}
