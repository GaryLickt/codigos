package codigos.Codigos_JAVA.Mini_projetos.Date;

import java.util.Calendar;

public class Msg_Boas_Vindas_Calendar{

	public static void main(String[] args) {
		Calendar c1 = Calendar.getInstance();
		int hora = c1.get(Calendar.HOUR_OF_DAY);
		int minuto = c1.get(Calendar.MINUTE);
		int segundo = c1.get(Calendar.SECOND);

		System.out.println(hora + ":" + minuto + ":" + segundo);
if(hora > 6 && hora < 12){
			System.out.println("Bom Dia");
		}else if(hora > 12 && hora < 18){
			System.out.println("Boa Tarde");
		}else{
			System.out.println("Boa Noite");
		}
	}
}