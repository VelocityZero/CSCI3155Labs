/*			(a)
 *
A ::= A & A | V
V ::= a | b
 */
import scala.until.parsing.combinator._

class JSON extends JavaTokenParser{
	def A: Parser[Any] = A & A | V
	def V: Parser[Any] = a | b
}