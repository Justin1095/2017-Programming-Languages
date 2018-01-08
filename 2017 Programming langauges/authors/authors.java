import java.io.File;
import javax.xml.parsers.*;
import org.w3c.dom.*;

/**
 Justin Seda
 Programming Languages 11am
 Professor DeVito 
 Nov. 30, 2017
 
 This program reads in a xml and finds specific parts of the file.
 */
public class authors
{
    public static void main(String argv[])
    {
        int i,j;
        try
        {
            /*Parsing a file*/
            File xml = new File("authors.xml"); //grabs the file
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance(); //creates a DocumentBuilderFactory
            DocumentBuilder dbuild = dbf.newDocumentBuilder(); //creates a Document Builder
            Document doc =dbuild.parse(xml);//parse the xml gile to a document 
            doc.getDocumentElement().normalize();
            
            System.out.println("The Root element tag is: "+ doc.getDocumentElement().getNodeName()); //gets root
            
            NodeList List = doc.getElementsByTagName("Author"); //creates nodeList
            Node nNode= List.item(0); //creates a node from the list's item
                    
            System.out.println("There is a total of " + List.getLength() + " authors in this XML file\n"); //gets length of the list     
            for(i = 0; i< List.getLength(); i++) //goes through each author
            {             
              nNode = List.item(i); //creates nodes for each list item 
              if(nNode.getNodeType() == Node.ELEMENT_NODE)
              {
                  Element elem = (Element)nNode;
                  System.out.println("The Name of author Number " + (i +1) + " is: " + elem.getElementsByTagName("Name").item(0).getTextContent());  //gets authors       
                                    
                  NodeList books = (elem).getElementsByTagName("BookTitle"); //creates new nodelist for the books
                  
                  System.out.println("This author wrote " + books.getLength() + " books. The books are: "); //number of books
                  for(j = 0; j< books.getLength();j++) //goes through each book the author made 
                  {
                      nNode = List.item(j); //creates nodes for each books item
                      if(nNode.getNodeType() == Node.ELEMENT_NODE)
                      {
                          System.out.println( elem.getElementsByTagName("BookTitle").item(j).getTextContent()); //each book that the author made 
                      }
                  }
                  System.out.println("");
              }
            }             
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}