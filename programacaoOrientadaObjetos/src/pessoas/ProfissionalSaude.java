package pessoas;

public class ProfissionalSaude extends Funcionario{
    private String especializacao;
    public ProfissionalSaude(String nome, int rg, int idade, double salario, String especializacao){
        super(nome, rg, idade, salario);
        this.especializacao = especializacao;
    }
    
    public ProfissionalSaude(String nome, int rg, int idade, double salario){
        super(nome, rg, idade, salario);
        this.especializacao = "Clínico Geral";
    }
    
    @Override
    public String toString() {
        return super.toString()+"Especializacao: " + especializacao + "\n";
    }

    public String getEspecializacao() {
        return especializacao;
    }

    public void setEspecializacao(String especializacao) {
        this.especializacao = especializacao;
    }
    
}
