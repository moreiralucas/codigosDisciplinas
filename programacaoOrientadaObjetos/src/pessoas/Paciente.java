package pessoas;

import java.util.Date;

public abstract class Paciente extends Pessoa{
    private int numProntuario;
   public Paciente(String nome, int rg, int idade, int idProntuario){
       super(nome, rg, idade);
       this.numProntuario = idProntuario;
   }
   
   @Override
   public String toString(){
       return super.toString()+"Número de Prontuário: "+numProntuario+"\n";
   }
}
