import java.util.Scanner;
import java.util.ArrayList;


public class Main {

        public static int num = 1;
        public static int now = 0;
        public static String some[] = {""};
        public static ArrayList<String> arr = new ArrayList<String>();
	public static ArrayList<String> im = new ArrayList<String>();
        public static int error = 0;
        public static int prev = 0;



        public static void main(String [] args) {
		prev = 0;
                System.out.print(">");
                String answer = " ";
                String input = "";
                Scanner s = new Scanner(System.in);
                String sub = "";
                try {

                        input = s.nextLine();
                        } catch (Exception e) {
                                        System.exit(0);
                        }

				finally{
                int sz = input.length();
                if(input.indexOf("let") > 0)
                {
                        sub = input.substring(input.indexOf('t')+2, sz-1);
                        input = arrange(sub, sub.length());
                        sz = input.length();
                }
                Find(input, sz);
                }

                for(int j=0; j<arr.size(); j++){
                        answer = arr.get(j);
                }


                int did = calcul(arr, 0);
                if(error==0)
                	System.out.println(did);
                else if(error==1)
                	System.out.println("(wrong-number-of-arguments 3)");
                else
                	 System.out.println("(wrong-number-of-arguments 1)");
                	

                arr.removeAll(arr);
		im.removeAll(im);
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

				if(curr<40 || curr==44 || curr==46 || curr>57)
				{	
					if(curr!=' ' && prev==1){
					System.out.println("(void-variable "+curr+")");
					main(some);							
				}}


                                if(curr=='(' && start==0)
                                {        start = i;
					prev++;
				}
                                else if(curr=='(' && start!=0)
                                {        end = end-1;
					prev++;
				}
                                else if(curr==')' && end==0)
                                {       end = i;
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

                                tit = "<" + (num-1) + ">";
                                str = str.replace(sub, tit);
                                if(arr.size()>=n)
                                        arr.set(n-1, str);
                                else
                                        arr.add(str);

                                sz = sub.length();

                                i=i-sz+1;
                                size=size-sz+1;
                                Find(sub, sz);
                        }
                        else if(check ==1){
                                if(arr.size()>=n)
                                        arr.set(n-1, str);
                                else
                                        arr.add(str);
                        }
                        else{}
                }
        }



	public static int calcul(ArrayList<String> s, int index){

                String todo = s.get(index);
                int value = 0;
                int i = 0;
                char curr;
                int subs = 0;
                int op = 0;
                int temp = 0;
                while(true){
                        curr = todo.charAt(i);

                    if(curr=='(')
                            op = 0;
                    else if(curr=='+')
                            op = 1;
                    else if(curr=='-')
                                op = 2;
                    else if(curr=='*')
                    {           op = 3;
                                value = 1;
                    }
                    else if(curr=='/')
                                op = 4;
                    else if(curr==')')
                            break;
                    else if(curr=='<')
                    {           i = i+1;
                                curr = todo.charAt(i);
                        subs = calcul(arr, (int)curr - 48);
                    }
                    else if(curr==' ')
                    { }
                    else{
                            if(subs != 0 && curr=='>')
                                curr = (char)(subs + 48);

                            if((todo.charAt(i+1))!=' ' && todo.charAt(i+1)!=')')
                                temp = temp*10 + ((int)curr - 48);

							else{
                                temp = temp*10 + ((int)curr - 48);

                                if(op == 1)
                                        value = value + temp;
                                else if(op == 2)
                                {       op = 20;
                                        value = temp;
                                }
                                else if(op == 3)
                                        value = value * temp;
                                else if(op == 4)
                                {       op = 40;
                                        value = temp;
                                }
                                else if(op == 20)
                                {       op = 30;
                                        value = value - temp;
                                }
                                else if(op == 30)
                                        value = value - temp;
                                else if(op == 40)
                                {       value = value / temp;
                                        op = 50;
                                }
                                else if(op == 50)
                                {       
                                        error=1;
                                }

                                temp = 0;
                    }}
                    i=i+1;
                }
                if(op==20)
                        value = - value;
                if(op==40)
                {      
                        error = 2;
                }

                        return value;
                }

                public static String arrange(String str, int size){

                		char now = ' ', var = ' ', change = ' ';
                        String sub, old, tit;
                        int szz, j;
                        int count = 1;
                        int cut = 0;
                        int here = 0;
                        int check = 0;

                        int sz = str.length();

                        if(str.indexOf("let") > 0)
                        {      
                        		for(j=str.indexOf('l'); count!=0; j++)
                        		{	
                        			if(str.charAt(j)=='(')
                        				count++;
                        			else if(str.charAt(j)==')')
                        				count--;
                        		}
                                sub = str.substring(str.indexOf('t')+2, j-2);
                                old = str.substring(str.indexOf('l')-1, j-1);
                                szz = sub.length();
                                tit = arrange(sub, szz);
                                str = str.replace(old, tit);
                                sz = str.length();
                        }

                        for(here = 0; here<sz; here=here+1)
                        {		
                                now = str.charAt(here);

                                if(check!=2 && now == '(')
                                        check = 1;
                                else if(now == ')' && check==3)
                                {       cut = here + 2;
                                        check = 0;
                                }
                                else if(now==')' && (check==1 || check==2))
                                        check = 0;
                                else if(check==1 && now!='+' && now!='-' && now!='*' && now!='/' && now!=' ')
                                {       var = now;
                                        check = 2;
                                }
                                else if(check==1 && (now=='+' || now=='-' || now=='*' || now=='/' || now==' '))
                                {     
                                        check = 0;
                                }
				else if(check == 2 && now=='(')
				{
					int start = here;
					int end = 0;
					check = 3;
					for( ; now!=')'; here++)
					{	now = str.charAt(here);
					}	
					here = here-1;
					end = here;
					String s = str.substring(start, end+1);
       

					im.add(s);
					int c = calcul(im, 0);
					change = (char)(c+48);
	
					str = str.replace(var, change);
				}
                                else if(check == 2 && now!=' ')
                                {       change = now;
                                                check = 3;
                                        str = str.replace(var, change);
                                }
                                else{}
                        }
                        
                        
                        String rt = str.substring(cut, sz);
//                        System.out.println(str);
  //                      System.out.println(rt);
                        return rt;
                }
                }    
