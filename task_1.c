#include <superkarel.h>
void turn_right(){
    set_step_delay(10);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(100);
}

void (turn_around()){
    set_step_delay(10);
    turn_left();
    turn_left();
    set_step_delay(100);
}

void (face_north()){
    while (!facing_north()){
        turn_left();
    }
}

void (move_up()){
    face_north();
    while (right_is_blocked()){        
        step();
    }
}
void (move_up1()){
    face_north(); 
    while (left_is_blocked()){        
        step();
    }

}

void (move_down()){
    turn_right();
    while (front_is_clear()){
        step();
    }
}

void (move_down1()){
    turn_left();
    while (front_is_clear()){
        step();
    }
}

void (spawn_point()){
    put_beeper();
    
    if (front_is_blocked()){
         turn_left();
         step();
}
    else{
    while (front_is_clear()){
    step();
        }
        face_north();
    }
}

void (return_to_start()){

      while (!beepers_present()){
        //move_up();
        while (left_is_blocked() && !beepers_present() && front_is_clear()){
        step();
        }
        if (left_is_clear()){
            turn_left();
            step();
       // while (right_is_blocked()){
        
           // step();
            //}
            
           // if (right_is_clear()){
               // move_down();
            //} 
        } 
        else if (left_is_blocked() && front_is_clear()){
        }
        
         else if (left_is_blocked() && front_is_blocked() && right_is_blocked()){
            turn_around();
        }
        
        else if (left_is_blocked() && front_is_blocked()){
            turn_right();
        }
       
        //else{
          //  move_up();
        //}
    }
}
void (move_karel()){
        while (!beepers_present()){
        //move_up();
        while (right_is_blocked() && !beepers_present() && front_is_clear()){
        step();
        }
        if (right_is_clear()){
            turn_right();
            step();
       // while (right_is_blocked()){
        
           // step();
            //}
            
           // if (right_is_clear()){
               // move_down();
            //} 
        } 
        else if (right_is_blocked() && front_is_clear()){
        }
        
         else if (left_is_blocked() && front_is_blocked() && right_is_blocked()){
            turn_around();
        }
        
        else if (right_is_blocked() && front_is_blocked()){
            turn_left();
        }
        
        //else{
          //  move_up();
        //}
    }
}
    int main (){
    turn_on("task_1.kw");
    set_step_delay(100);
    
    spawn_point();
    
        while (!beepers_present()){  
            move_karel();
        }
        
    if (beepers_present()){
            pick_beeper();
            face_north();
    while (!beepers_present()){
            return_to_start(); 
           }     
           pick_beeper();
           face_north();
           turn_left();        
               turn_off();        
                return 0;
            }
} 
