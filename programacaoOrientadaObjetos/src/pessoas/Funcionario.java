package pessoas;

import java.util.Date;
public abstract class Funcionario extends Pessoa{
    private double salario;
    private boolean ativo=true;
    
    public Funcionario(String nome, int rg, int idade, double salario){
        super(nome, rg, idade);
        this.salario = salario;
    }

    @Override
    public String toString() {
        return super.toString()+"Salario: "+salario+"\nAtivo: "+ativo+"\n";
    }
    
    public boolean getAtivo(){
        return ativo;
    }
    
     
   public boolean autentica(String nome, String senha){
       boolean status;
       if(nome.equals(super.getNome())){
           System.out.println("Funcionario " + super.getNome() + " autenticado com sucesso!");
           status = true;
       }
       else{
           System.out.println("Usuario ou senha invalida!");
           status = false;
       }
       return status;
   }
}
