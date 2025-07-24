import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

class calculate extends JFrame implements ActionListener {
    JTextField t1;
    JTextField t2;
    JButton b1,b2,b3,b4;
    JLabel l;
    calculate(){
        t1 = new JTextField();
        t2= new JTextField();
        b1 = new JButton();
        b2 = new JButton();
        b3 = new JButton();
        b4 = new JButton();
        l= new JLabel()
        int num1= Integer.pharseInt(t1.getText());
        int num2= Integer.pharseInt(t2.getText());
        b1.addActionListener(e->
        {
            int value = num1 + num2;
            l.setText(value);

        });
        b2.addActionListener(e->
        {
            int value = num1 - num2;
            l.setText(value);

        });
        b3.addActionListener(e->
        {
            int value = num1 * num2;
            l.setText(value);

        });
        b4.addActionListener(e->
        {
            int value = num1 / num2;
            l.setText(value);

        });
        add(t1);
        add(t2);
        add(b1);
        add(b2);
        add(b3);
        add(b4);
        add(l);
        setLayout(new FlowLayout());
        setSize(500,500);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    }
}
class demo{
    public static void main(String arge[]){
        calculate ob = new calculate();
    }
}
