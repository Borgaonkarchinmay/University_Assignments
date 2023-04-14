import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.Servlet;
import jakarta.servlet.ServletConfig;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.sql.*;
import java.util.*;

/**
 * Servlet implementation class FirstServlet
 */
/**
 * @author preetham
 *
 */

@WebServlet("/Studentform")
public class Studentform extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	//Attributes
	static Connection con = null;

    /**
     * @see HttpServlet#HttpServlet()
     */
    public Studentform() {
        System.out.println("FirstServlet Constructor called!");
        
        try {
			Class.forName("com.mysql.jdbc.Driver");
			
			//establish a connection
			con = DriverManager.getConnection(
			"jdbc:mysql://localhost:3306/homedb?characterEncoding=utf8", "root", "Chinmaypb@1032"
			);
			System.out.println("Connection established successfully!!");
			
		}
		catch(Exception e) {
			System.out.println(e);
		}
        
    }

	/**
	 * @see Servlet#init(ServletConfig)
	 */
	public void init(ServletConfig config) throws ServletException {
		System.out.println("FirstServlet \"Init\" method called");
	}

	/**
	 * @see Servlet#destroy()
	 */
	public void destroy() {
		System.out.println("FirstServlet \"Destroy\" method called");
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
		
			System.out.println("FirstServlet \"Service\" method(inherited) called");
			System.out.println("FirstServlet \"DoGet\" method called");
			response.setContentType("text/HTML");
			
			int vid;
			String model;
			String mode;
			
			// Prepare statement == Fetch ==> Database vehicle records
			PreparedStatement st = null;
			st = con.prepareStatement("select * from vehicle");
			
			ResultSet resSet = st.executeQuery(); // Reocords from database fetched
			
			// Send HTML document as response
			PrintWriter out = response.getWriter();
	
			out.println("<html>"
					+ "<title>Vehicle Details</title>"
					+ "<body>");
					
			out.println("<h1> <center> Welcome to Vehicle Information Portal </center> </h1>");
			out.println("<style>");
			out.println("table{"
							+ "	font-size : 25px;"
							+ "text-align: center;"
							+ "margin-left:auto;"
							+ "margin-right:auto;"
							+ "width:90%;"
							+ "border-spacing: 10px 10px;"
							+ "}"
							+ "td{"
							+ "padding : 10px;"
							+ "}");
			out.println("</style>");
					
			out.println("<br>"
					+ "<br>"
					+ "<table>"
					+ "<tr>"
					+ "<th>Vehicle ID</th>"
					+ "<th>Model</th>"
					+ "<th>Type</th>"
					+ "</tr>");
			
			while(resSet.next())
				{	
					vid = resSet.getInt(1);
					model = resSet.getString(2);
					mode = resSet.getString(3);
					out.println("<tr>"
							+ "<td>" + vid + "</td>"
							+ "<td>" + model + "</td>"
							+ "<td>" + mode + "</td>"
							+ "</tr>");
				}
			
			out.println("</table>");
			out.println("</body>");
			out.println("</html>");
			con.close();
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("FirstServlet \"Service\" method(inherited) called");
        System.out.println("FirstServlet \"DoPost\" method called");
        PrintWriter out = response.getWriter();
        out.write("<html><body><h4>Welcome to Student Information Portal</h4></body></html>");
        
	}

}