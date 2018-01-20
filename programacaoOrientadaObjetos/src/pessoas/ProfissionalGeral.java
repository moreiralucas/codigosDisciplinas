package pessoas;

public class ProfissionalGeral extends Funcionario{
    private String funcao;
    public ProfissionalGeral(String nome, int rg, int idade, double salario, String funcao){
        super(nome, rg, idade, salario);
        this.funcao = funcao;
    }
    
    @Override
    public String toString(){
        return super.toString()+"Função: "+funcao+"\n";
    }
}
