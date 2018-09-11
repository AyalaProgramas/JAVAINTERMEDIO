package interfas.program;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;

public class diseño {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					diseño window = new diseño();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public diseño() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		final JLabel lblSaludo = new JLabel("");///dentro de un metodo tiene qe ser secuencial las llamadas
		lblSaludo.setFont(new Font("Times New Roman", Font.PLAIN, 17));
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		frame.getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);
		
		JButton btnSaludar = new JButton("Saludar");//crea la instancia
		btnSaludar.addActionListener(new ActionListener() {//escucha el evento//  clase abstracrta clase que esta dentro se una clase
			public void actionPerformed(ActionEvent arg0) {
				
				lblSaludo.setText("hola mundo");
			}
		});
		btnSaludar.setBounds(155, 103, 89, 23);
		panel.add(btnSaludar);
		
		//JLabel lblSaludo = new JLabel("");//la subo arriba xq no puede llamar
		lblSaludo.setBounds(43, 175, 314, 58);
		panel.add(lblSaludo);
	}
}
