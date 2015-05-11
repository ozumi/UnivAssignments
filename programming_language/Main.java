import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;


public class Main {

	public static int num = 1;
	public static int now = 0;
	public static String some[] = {""};
	public static ArrayList<String> arr = new ArrayList<String>();
	
	public static void main(String [] args) {
	
		System.out.print(">");
		String answer = " ";	
		String input = "";
		Scanner s = new Scanner(System.in);

		try {

			input = s.nextLine();
			} catch (Exception e) {
					System.exit(0);
			} 	 

		finally{
		int sz = input.length();
		Find(input, sz);
		}

		for(int j=0; j<arr.size(); j++){
			answer = arr.get(j);
			System.out.println(answer);
		}
		s.close();
		arr.removeAll(arr);
		num = 1;
		now = 0;
		main(some);
	}
	

	
	public static void Find(String str, int size){
		now = now + 1;
		int n = now;
		int start, end = 0;
		int i = 0;
		
		int check = 0;
		char curr;
		
		String tit = " ";
		int sz = 0;
		

		while(i<size){
			start = 0;
			end = 0;
	
			while(end<=0){
				curr = str.charAt(i);
				if(curr=='(' && start==0)
					start = i;
				else if(curr=='(' && start!=0)
					end = end-1;
				else if(curr==')' && end==0)
				{	end = i;
					if(end==size-1)
						check=1;
				}
				else if(curr==')' && end!=0)
					end = end + 1;
				else{};
					i=i+1;
			}
			if(start!=0 && check==0){	
				String sub = str.substring(start, end+1);
				num = num + 1;
				tit = "<E"+num+">";
				str = str.replace(sub, tit);
				if(arr.size()>=n)
					arr.set(n-1, "<E" + n + "> => " + str);
				else
					arr.add("<E" + n + "> => " + str);
				
				sz = sub.length();
				i=i-sz+1;
				size=size-sz+1;
				Find(sub, sz);
			}
			else if(check ==1){
				if(arr.size()>=n)
					arr.set(n-1, "<E" + n + "> => " + str);
				else
					arr.add("<E" + n + "> => " + str);
			}
			else{}
		}
	}
}

