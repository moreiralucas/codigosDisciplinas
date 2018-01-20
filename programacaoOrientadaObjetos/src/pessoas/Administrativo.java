package pessoas;

public class Administrativo extends Funcionario{
    private String login;
    private String senha;
    
    public Administrativo (String nome, int rg, int idade, double salario, String login, String senha){
        super(nome, rg, idade, salario);
        this.login = login;
        this.senha = senha;
    }
    
    @Override
    public String toString(){
        return super.toString()+"Login no sistema: "+login+"\n";
    }
    
    public boolean loginCheck(String senha){
        return this.senha.equals(senha);
    }
}
