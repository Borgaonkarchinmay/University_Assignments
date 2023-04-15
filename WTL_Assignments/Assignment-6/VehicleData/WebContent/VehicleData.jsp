<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.io.*,java.sql.*" %>

<!DOCTYPE html>

<html>
	<head>
		<meta charset="UTF-8">
		<title>Insert title here</title>
		
		<style>
			table,th,td{
			border : 2px solid;
			}
			table{
				font-size : 20px;
				text-align:center;
				margin-left:auto;
				margin-right:auto;
				width:90%;
			/*  	border-spacing: 5px; */
			}
			td{
				padding : 13px;
			}
			h1{
				font-size : 40px;
				text-align : center;
			}
			button{ 
			  background-color: #008CBA;
			  border: none;
			  color: white;
			  padding: 15px 32px;
			  text-align: center;
			  text-decoration: none;
			  display: inline-block;
			  font-size: 24px;
			  border-radius : 8px;
			  width : 25%;
			}
			div{
				text-align : center;s
			}
		</style>
		
	</head>
	
	<body>
		<h1>Vehicle Data</h1>
		<%! static Connection con = null;%>
		
		<%
			try {
				Class.forName("com.mysql.jdbc.Driver");
				
				//establish a connection
				con = DriverManager.getConnection(
				"jdbc:mysql://localhost:3306/homedb?characterEncoding=utf8", "root", "Chinmaypb@1032"
				);
				System.out.println("Connection established successfully!!");
				
			}catch(Exception e) {
				System.out.println(e);
			}
		%>
		
		<%
			try {
				
				System.out.println("FirstServlet \"Service\" method(inherited) called");
				System.out.println("FirstServlet \"DoGet\" method called");
				
				int vid;
				String model;
				String mode;
				
				// Prepare statement == Fetch ==> Database vehicle records
				PreparedStatement st = null;
				st = con.prepareStatement("select * from vehicle");
				
				ResultSet resSet = st.executeQuery(); // Reocords from database fetched
				
		%>
		
		<div>
		<table>
			<tr>
			<th>Vehicle ID</th>
			<th>Model</th>
			<th>Type</th>
			</tr>
			
			<% while(resSet.next()) { %>
				
				<tr>
					<td> <%= resSet.getInt(1) %></td>
					<td> <%= resSet.getString(2) %></td>
					<td> <%= resSet.getString(3) %></td>
				</tr>
				
			<%} %>
		</table> <br>
		
		<%
			}catch(Exception e){
				e.printStackTrace();
			}
		%>		
		
		<form action="index.html">
			<button>Go Home</button>   
		</form>
		</div> 
	
	</body>
</html>