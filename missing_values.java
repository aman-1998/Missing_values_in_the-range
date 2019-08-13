import java.util.*;
import java.lang.*;
import java.io.*;

class MISS
{
	public static void main(String args[])
	{
		int x,count;
		Scanner in=new Scanner(System.in);
		ArrayList<Integer> A=new ArrayList<Integer>();
		do
		{
			System.out.print("Enter input: ");
			x=in.nextInt();
			A.add(x);
			System.out.print("Enter \'0\' to continue and any other key to quit : ");
			x=in.nextInt();
		}
		while(x==0);
		for(Integer i:A)
			System.out.print(i+" ");
		System.out.print("\nEnter range: ");
		int start=in.nextInt();
		int end=in.nextInt();
		Collections.sort(A);
		int s=Collections.binarySearch(A,start);
		int e=Collections.binarySearch(A,end);
		System.out.print("\nMissing Elements: ");
		for(int i=s+1;i<=e;i++)
		{
			count=A.get(i)-A.get(i-1)-1;
			x=A.get(i-1)+1;
			while((count--)!=0)
				System.out.print((x++)+" ");
		}
	}
}