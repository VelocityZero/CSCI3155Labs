object Lab2 {
  import jsy.lab2.ast._
  // ============================= Notes ===============================
  /*
   * CSCI 3155: Lab 2
   * Jacob Rail
   * 
   * Partner: Brian Bauer
   * Collaborators: Dana
   */

  /*
   * Fill in the appropriate portions above by replacing things delimited
   * by '<'... '>'.
   * 
   * Replace the 'throw new UnsupportedOperationException' expression with
   * your code in each function.
   * 
   * Do not make other modifications to this template, such as
   * - adding "extends App" or "extends Application" to your Lab object,
   * - adding a "main" method, and
   * - leaving any failing asserts.
   * 
   * Your lab will not be graded if it does not compile.
   * 
   * This template compiles without error. Before you submit comment out any
   * code that does not compile or causes a failing assert.  Simply put in a
   * 'throws new UnsupportedOperationException' as needed to get something
   * that compiles without error.
   */
  

// =========================== Declarations =============================

  type Env = Map[String, Expr]
  val emp: Env = Map()
  def get(env: Env, x: String): Expr = env(x)
  def extend(env: Env, x: String, v: Expr): Env = {
    require(isValue(v))
    env + (x -> v)
  }

// =========================== Functions ================================
  
// ----------------------------------------------------------------------
// ---------------------------- toNumber --------------------------------
  def toNumber(v: Expr): Double = {
    require(isValue(v))
    (v: @unchecked) match {
      case N(n) => n
	  case B(b) => if(b) 1 else 0;
	  case _ => Double.NaN
    }
  }

// ---------------------------------------------------------------------- 
// --------------------------- toBoolean --------------------------------
  def toBoolean(v: Expr): Boolean = {
    require(isValue(v))
    (v: @unchecked) match {
      case B(b) => b
	  case N(n) => (n != 0) 
      case _ => false // need speacial cases to handle undefined. 
    }
  }

// ----------------------------------------------------------------------
// ------------------------------ eval ----------------------------------
  def eval(env: Env, e: Expr): Expr = {
    e match {
    /* Base Cases */
	// catches everything that is a number, bool, or undefined
	// this is also the base case for the recussive calls
    case _ if (isValue(e)) => e 
    case Var(x) => eval(env, get(env, x))
  
      /* Inductive Cases */
	  case Binary(bop, e1, e2) => {
		// continue down the parse tree.
		lazy val a = eval(env, e1)
		lazy val b = eval(env, e2)
		
		bop match {
		// ComparisonSpec	
			case Eq => B(toNumber(a) == toNumber(b))
			case Ne => {
				if(toNumber(a).isNaN && toNumber(b).isNaN) B(false)
				else B(toNumber(a) != toNumber(b))
			}
			case Lt => B(toNumber(a) < toNumber(b))
			case Le => B(toNumber(a) <= toNumber(b))
			case Gt => B(toNumber(a) > toNumber(b))
			case Ge => B(toNumber(a) >= toNumber(b))
			
		// AndOrSpec
			case And => {
				/*
				val andOr = (a, b)
				val answer = B(toBoolean(andOr._1) && toBoolean(andOr._2))
				
				andOr match{
					case (B(_), B(_)) => answer
					case _ => N(toNumber(answer))
				}
				*/
				
				}
				
			}
			case Or => {
				val Or = (a, b)
				val answer = B(toBoolean(a) || toBoolean(b))
				Or match {
					case (B(b), N(n)) => if(b) B(b) else N(n)
					case (N(n), B(b)) => if(b) B(b) else N(n)
					case _ => answer
				}
			}
				
		// ArithmeticSpec
			case Plus => N(toNumber(a) + toNumber(b))
			case Minus => N(toNumber(a) - toNumber(b))
			case Times => N(toNumber(a) * toNumber(b))
			case Div => N(toNumber(a) / toNumber(b))
			
		// SeqSpec
			case Seq => a; b
		}
	}
	
	case Unary(uop, e1) => {
			
		val a = eval(env, e1)
		uop match {
			case Neg => N(-toNumber(a))
			case Not => B(!toBoolean(a))
		}
	}
	
	// ConstSpec
	case ConstDecl(x, e1, e2) => {
		var env2 = extend(env, x, eval(env, e1))
		eval(env2, e2)
	}
	
	case If(e1, e2, e3) => {
		if (toBoolean(eval(env, e1))) eval(env, e2) else eval(env, e3)
	}
	
      case Print(e1) => println(eval(env, e1)); Undefined
      case _ => throw new UnsupportedOperationException
    }
  }
      
  def evaluate(e: Expr): Expr = eval(emp, e)
    
}
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
