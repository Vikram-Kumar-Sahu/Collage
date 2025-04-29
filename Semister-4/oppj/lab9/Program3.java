import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Stopwatch extends JFrame implements ActionListener {
    private long startTime;
    private boolean running;
    private JLabel displayLabel;
    private JButton startButton, stopButton, resetButton;

    public Stopwatch() {
        setTitle("Stopwatch");
        setSize(300, 150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        displayLabel = new JLabel("00:00:000");
        displayLabel.setFont(new Font("Verdana", Font.PLAIN, 30));
        add(displayLabel);

        startButton = new JButton("Start");
        stopButton = new JButton("Stop");
        resetButton = new JButton("Reset");

        add(startButton);
        add(stopButton);
        add(resetButton);

        startButton.addActionListener(this);
        stopButton.addActionListener(this);
        resetButton.addActionListener(this);

        setVisible(true);

        Timer timer = new Timer(10, e -> updateDisplay());
        timer.start();
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == startButton) {
            startTime = System.currentTimeMillis();
            running = true;
        } else if (e.getSource() == stopButton) {
            running = false;
        } else if (e.getSource() == resetButton) {
            running = false;
            displayLabel.setText("00:00:000");
        }
    }

    private void updateDisplay() {
        if (running) {
            long elapsed = System.currentTimeMillis() - startTime;
            int minutes = (int) (elapsed / 60000);
            int seconds = (int) ((elapsed % 60000) / 1000);
            int milliseconds = (int) (elapsed % 1000);

            displayLabel.setText(String.format("%02d:%02d:%03d", minutes, seconds, milliseconds));
        }
    }

    public static void main(String[] args) {
        new Stopwatch();
    }
}
