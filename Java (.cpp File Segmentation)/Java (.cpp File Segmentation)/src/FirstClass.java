/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 19.03.2021-11.04.2021 
* @course  2B
* <p>
*  program.cpp dosyasini class'lara bolup class'lardaki public metodlari ve 
*  bu metodlarin parametrelerini,geri donus tipini ve kalitim alinan class lari listelemek
* </p>
*/

import java.io.IOException;
import java.io.BufferedReader;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.io.FileReader;

public class FirstClass {
	
	public static void main(String[] args) throws IOException
	{
		File myObj = new File("src\\program.cpp");

    	BufferedReader br = new BufferedReader(new FileReader(myObj));
  	    int data = 0;  //okunacak karakterin int karsiligi   
  	    data=br.read();
  	    char character = (char) data; 
    	
		try {		     
		       Okuma.ClassOkuma(character, br);
		       System.out.println("\n\nSuper Siniflar ");
		       for (String key : Okuma.KalitimClass.keySet()) // iterate over all keys
		           System.out.println("   "+key + " : " + Okuma.KalitimClass.get(key)); // print key and va*/
		         br.close();
		      } 
		    
		    catch (FileNotFoundException e) {
		        System.out.println("An error occurred.");
		        e.printStackTrace();
		      }			
	}
}