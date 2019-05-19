package codes;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

public class Gui extends JFrame{
	private JButton reg;
	private JButton custom;
	
	public Gui() {
		super("The title");
		setLayout(new FlowLayout());
		
		reg = new JButton("reg button");
		add(reg);
		
		//Icon b = new ImageIcon(getClass().getResource("b.png"));
		//Icon x = new ImageIcon(getClass().getResource("x.png"));
		//custom = new JButton("custom", b);
		//custom.setRolloverIcon(x);
		//add(custom);
		
		HandlerClass handler = new HandlerClass();
		reg.addActionListener(handler);
		//custom.addActionListener(handler);
	}
	
	private class HandlerClass implements ActionListener {
		public void actionPerformed(ActionEvent event) {
			JOptionPane.showMessageDialog(null, String.format("%s", event.getActionCommand()));
		}
	}
	
	/*private JPanel mousepanel;
	private JLabel statusbar;
	private String details;
	
	public Gui() {
		super("title");
		
		mousepanel = new JPanel();
		mousepanel.setBackground(Color.WHITE);
		add(mousepanel, BorderLayout.CENTER);
		
		statusbar = new JLabel("default");
		add(statusbar, BorderLayout.SOUTH);
		addMouseListener(new Mouseclass());
		
		Handlerclass handler = new Handlerclass();
		mousepanel.addMouseListener(handler);
		mousepanel.addMouseMotionListener(handler);
	}
	
	private class Mouseclass extends MouseAdapter {
		public void mouseClicked(MouseEvent event) {
			details = String.format("You clicked %d times ", event.getClickCount());
			
			if (event.isMetaDown()) {
				details += "with right mouse button";
			} else if (event.isAltDown()) {
				details += "with center mouse button";
			} else {
				details += "with left mouse button";
			}
			
			statusbar.setText(details);
		}
	}
	
	private class Handlerclass implements MouseListener, MouseMotionListener {
		public void mouseClicked(MouseEvent event) {
			statusbar.setText(String.format("Clicked at %d,%d", event.getX(), event.getY()));
		}
		public void mousePressed(MouseEvent event) {
			statusbar.setText("you pressed down the mouse");
		}
		public void mouseReleased(MouseEvent event) {
			statusbar.setText("you released the button");
		}
		public void mouseEntered(MouseEvent event) {
			statusbar.setText("you entered the area");
			mousepanel.setBackground(Color.RED);
		}
		public void mouseExited(MouseEvent event) {
			statusbar.setText("the mouse has left the window");
			mousepanel.setBackground(Color.WHITE);
		}
		// these are mouse motion events
		public void mouseDragged(MouseEvent event) {
			statusbar.setText("you are dragging the mouse");
		}
		public void mouseMoved(MouseEvent event) {
			statusbar.setText("you moved the mouse");
		}
	}*/
}
