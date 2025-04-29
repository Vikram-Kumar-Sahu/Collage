import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class RegistrationForm extends JFrame implements ActionListener {

    // Components
    JLabel nameLabel, emailLabel, phoneLabel, passLabel, msgLabel;
    JTextField nameField, emailField, phoneField;
    JPasswordField passField;
    JButton submitBtn;

    RegistrationForm() {
        // Set window title
        super("Registration Form");

        // Set layout
        setLayout(new GridLayout(6, 2, 10, 10)); // 6 rows, 2 columns

        // Create components
        nameLabel = new JLabel("Name:");
        emailLabel = new JLabel("Email:");
        phoneLabel = new JLabel("Phone:");
        passLabel = new JLabel("Password:");
        msgLabel = new JLabel(); // Message label for output

        nameField = new JTextField();
        emailField = new JTextField();
        phoneField = new JTextField();
        passField = new JPasswordField();

        submitBtn = new JButton("Register");

        // Add ActionListener to button
        submitBtn.addActionListener(this);

        // Add components to frame
        add(nameLabel);
        add(nameField);
        add(emailLabel);
        add(emailField);
        add(phoneLabel);
        add(phoneField);
        add(passLabel);
        add(passField);
        add(new JLabel()); // Empty cell
        add(submitBtn);
        add(new JLabel("Output:"));
        add(msgLabel);

        // Frame settings
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    // Handle button click
    public void actionPerformed(ActionEvent e) {
        String name = nameField.getText();
        String email = emailField.getText();
        String phone = phoneField.getText();
        String password = new String(passField.getPassword());

        // Simple validation
        if (name.isEmpty() || email.isEmpty() || phone.isEmpty() || password.isEmpty()) {
            msgLabel.setText("Please fill all fields!");
        } else {
            msgLabel.setText("Registered: " + name + ", " + email);
        }
    }

    // Main method
    public static void main(String[] args) {
        new RegistrationForm();
    }
}
