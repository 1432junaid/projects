import java.util.Scanner;
import java.lang.reflect.*;
class Demo{
	Demo(){}
	Demo(int x){}
	public static void method1(int x, int y){}
	public int method2(int x){
		return 0;
	}
	public void sum(int x, int y){}
}

class Demo1{
	Demo1(){}
	Demo1(int x){}
	public void demo1Method(int x, String s){}
	public void text(int x, int y){}
}

class ClassInfo{
	public static void main(String... args){
		Demo obj1 = new Demo();
		Class c1 = Demo.class;
		Method[] ma 	= c1.getDeclaredMethods();
		Constructor[] cu= c1.getDeclaredConstructors();
		try{
			c1 = Class.forName(args[0]);
		}catch(Exception e){
			e.printStackTrace();
		}
		String ClassName = c1.getName();	// Class Name
		System.out.println(ClassName +" {");
		for(int i = 0 ; i < ma.length; i++){		// for Methods name
                        int mod = ma[i].getModifiers();		//get all modifiers [public,static ....]
                        System.out.print ("\t"+Modifier.toString(mod)+" ");
                        System.out.print (ma[i].getReturnType()+" ");
                        System.out.print (ma[i].getName());
                        Class[] rTypes = ma[i].getParameterTypes();
                        System.out.print("(");
                        for(int k = 0; k<rTypes.length; k++){
				if(rTypes.length >1){
					System.out.print(" "+rTypes[k]);
				}else
                                System.out.print(rTypes[k]);
                        }
                        System.out.print(")");
                        Class[] ex = ma[i].getExceptionTypes();
                        for(int m = 0; m < ex.length; m++){
                                System.out.println(ex[m]);
                        }
                        System.out.println();
                }
		for(int i = 0 ; i < cu.length; i++){		//for Constructor
                        int mod = ma[i].getModifiers();
                        System.out.print ("\t"+Modifier.toString(mod)+" ");
                        System.out.print (cu[i].getName());
                        Class[] rTypes = cu[i].getParameterTypes();
                        System.out.print("(");
                        for(int k = 0; k<rTypes.length; k++){
                                System.out.print(rTypes[k]);
                        }
                        System.out.print(")");
                        Class[] ex = ma[i].getExceptionTypes();
                        for(int m = 0; m < ex.length; m++){
                                System.out.println(ex[m]);
                        }
                        System.out.println();
                }
		System.out.println(" }");
	}
}
