// Applets are deprecated after JDK 8
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*<applet code="Calculator" width="400" height="400"></applet>*/
public class Calculator extends Applet implements ActionListener
{
 TextField t;
 Panel p1,p2;
 Button b[]=new Button[10];
 Button add,sub,mod,div,mul,clr,eql;
 char op;
 float result;
 int num1,num2;
 public void init()                       
   {
     t=new TextField();
     add=new Button("+");
     sub=new Button("-");
     div=new Button("/");
     mul=new Button("*");
     clr=new Button("Clr");
     eql=new Button("Eql");
     mod=new Button("%");
     p1=new Panel();
     p2=new Panel();
     for(int i=0;i<10;i++)
     b[i]=new Button(""+i);
     setLayout(new GridLayout(6,4,1,1));
     p1.setLayout(new GridLayout(1,1));
     p2.setLayout(new GridLayout(5,4));
     p1.add(t);
     p2.add(add);
     p2.add(sub);
     p2.add(mul);
     p2.add(div);
     p2.add(clr);
     p2.add(mod);
     p2.add(eql);
     for(int i=0;i<10;i++)
     	p2.add(b[i]);
     add(p1);
     add(p2);
     add.addActionListener(this);
     sub.addActionListener(this);
     mul.addActionListener(this);
     div.addActionListener(this);
     clr.addActionListener(this);
     mod.addActionListener(this);
     eql.addActionListener(this);
     for(int i=0;i<10;i++)
     	b[i].addActionListener(this);
    }	
    public void actionPerformed(ActionEvent e)
    {
    	String input_string=e.getActionCommand();
    	char input_char=input_string.charAt(0);
    	if(Character.isDigit(input_char))
		{
    		t .setText(t.getText()+input_char);
    	}
    	else
    	
    		if(a.equals("add"))
    		{
    			num1=Integer.parseInt(t.getText());
    			op='+';
    			t.setText("");
    		}
    		else if(a.equals("sub"))
    		{
    		    num1=Integer.parseInt(t.getText());
    			op='-';
    			t.setText("");	
    		}
    		else if(a.equals("div"))
    		{
    		    num1=Integer.parseInt(t.getText());
    			op='/';
    			t.setText("");	
    		}
    		else if(a.equals("mul"))
    		{
    		    num1=Integer.parseInt(t.getText());
    			op='*';
    			t.setText("");	
    		}
    		else if(a.equals("mod"))
    		{
    		    num1=Integer.parseInt(t.getText());
    			op='%';
    			t.setText("");	
    		}
    		 if(a.equals("eql"))
    		{
    		    num2=Integer.parseInt(t.getText());
    			if(op=='+')
    		    result=num1+num2;
    		    else if(op=='-')
    		    result=num1-num2;
    		    else if(op=='*')
    		    result=num1*num2;
    		    else if(op=='/')
    		    result=num1/num2;
    		    else if(op=='%')
    		    result=num1%num2;
    		    t.setText(""+result);
    	    }
    	     if(a.equals("clr"))
    	    {
    	    	t.setText("");
    	    }
    	
    }
}
