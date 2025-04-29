import javax.swing.*; // Fix: Corrected the import statement
import java.awt.*;

public class one {
        public static void main(String[] args) {
                JFrame frame = new JFrame();
                JLabel label = new JLabel(); // Fix: Declare and create the label
                ImageIcon icon = new ImageIcon("gift.png");
                frame.setTitle("JFrame title goes here");
                label.setText("bro, do you even code?");
                label.setIcon(icon);
                label.setHorizontalTextPosition(JLabel.CENTER);
                label.setVerticalTextPosition(JLabel.TOP);
                label.setForeground(new Color((0x00FF00)));// Fix: Added semicolon and corrected typo
                label.setFont(new Font("My Boli",Font.PLAIN,20));                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                label.setBackground(Color.black);
                label.setOpaque(true);
                label.setVerticalAlignment(JLabel.CENTER);
                label.setHorizontalAlignment(JLabel.CENTER);
                label.setBounds(0,0,350,250);

                frame.setResizable(true);
                frame.setLayout(null);
                frame.setSize(420, 420);
                frame.setVisible(true);
                frame.add(label); // Fix: Add the label after it's declared
        }
}
