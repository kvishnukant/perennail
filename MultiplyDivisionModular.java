package multiply_division_module;

public class MultiplyDivisionModular {

	public static void main(String ar[])
	{
		int result=modular(10,3);
		System.out.println(multiply(10, 3));
		System.out.println(division(10, 3));
		System.out.println(result);
	}
	
	public static int multiply(int p,int q)
	{
		int result = 0;
		if( p < 0 && q < 0){
            p = -p;
            q = -q;
        }else if(q<0)
        {
        	int temp=0;
        	temp=p;
        	p=q;
        	q=temp;
        }

		   while(q != 0)               
		   {
		      if ((q & 1)==1)              
		         result=result+p; 
		      p<<=1;              
		      q>>=1;             
		   }
		return result;
		
	}
	
	
	public static int division(int p, int q)
	{
		int quotient=1;
		int divisor=q;
		if(p==q){
			//quotient=0;
			return 1;
			}
			/*if dividend is smaller than divisor then remainder=dividend*/
			if(p<q){
			//quotient=p;
			return 0;
			}
		while(p>=q){
			q<<=1;
			quotient<<=1;
			}
		q>>=1;
			quotient>>=1;
			
			quotient+=division(p-q,divisor);
		return quotient;
		
	}
	
	public static int modular(int p,int q)
	{
		int mod=p-(multiply(q, division(p, q)));
		return mod;
		
	}
}
