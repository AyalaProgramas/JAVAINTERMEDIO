import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.FileVisitor;
import java.nio.file.Path;
import java.nio.file.attribute.BasicFileAttributes;

public class EjemploFileVisitor implements FileVisitor<Path>{

	@Override
	public FileVisitResult postVisitDirectory(Path dir, IOException attrs) throws IOException {
		System.out.println("visitando el archivo " + dir.toString());
		
		// TODO Auto-generated method stub
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult preVisitDirectory(Path file, BasicFileAttributes attrs) throws IOException {
		System.out.println("entrando en"+ file.toString());
		// TODO Auto-generated method stub
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
		System.out.println("saliendo del directorio"+ file.toString());
		// TODO Auto-generated method stub
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult visitFileFailed(Path dir, IOException attrs) throws IOException {
		System.out.println("error visitando el archivo"+ dir.toString());
		// TODO Auto-generated method stub
		return FileVisitResult.CONTINUE;
	}

}
