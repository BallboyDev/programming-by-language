import javax.swing.*;

public class Gui{
	public static void main(String[] args){
		JFrame frame = new JFrame("Morph's Hous");
		JLabel label = new JLabel("Hello World");
		frame.add(label);
		frame.pack();
		frame.setVisible(true);
	}
}