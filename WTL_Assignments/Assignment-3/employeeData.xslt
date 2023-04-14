<?xml version = "1.0" encoding = "UTF-8"?>
<xsl:stylesheet version = "1.0" xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">    
    <xsl:template match = "/">
        
        <html>    
            <body>
                <h2>Employee Data</h2>
                <table border = "1">
                    <tr bgcolor = "#9acd32">
                    <th>Employee ID</th>
                    <th>Name</th>
                    <th>Department</th>
                    <th>Designation</th>
                    <th>Education</th>
                    <th>Salary</th>
                    </tr>
                    <xsl:for-each select="employeeData/employee">
                        
                        <tr>
                            <td><xsl:value-of select = "@empId"/></td>
                            <td><xsl:value-of select = "name"/></td>
                            <td><xsl:value-of select = "department"/></td>
                            <td><xsl:value-of select = "designation"/></td>
                            <td><xsl:value-of select = "education"/></td>
                            <td><xsl:value-of select = "salary"/></td>
                        </tr>

                    </xsl:for-each> 
                </table>
            </body> 
        </html>

    </xsl:template>
</xsl:stylesheet>
